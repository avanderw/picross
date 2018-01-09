
import com.google.gson.Gson;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import javax.imageio.ImageIO;

public class GenerateInfoFiles {

    public static void main(String[] args) throws IOException {
        Map<String, DirectoryInfo> index = new HashMap();
        Files.walk(Paths.get("./src/main/webapp/levels")).forEach(path -> {
            if (path.getNameCount() > 5) {
                String key = path.subpath(4, path.getNameCount() - 1).toString().replace("\\","/");
                index.putIfAbsent(key, new DirectoryInfo());

                if (path.toString().endsWith(".png")) {
                    LevelInfo level = new LevelInfo();
                    level.path = path.subpath(path.getNameCount() - 1, path.getNameCount()).toString();

                    BufferedImage img;
                    try {
                        img = ImageIO.read(path.toFile());
                        level.width = img.getWidth();
                        level.height = img.getHeight();
                    } catch (IOException ex) {
                        Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
                    }

                    index.get(key).levels.add(level);
                } else if (Files.isDirectory(path)) {
                    index.get(key).directories.add(path.subpath(path.getNameCount() - 1, path.getNameCount()).toString());
                }
            }
        });
        index.entrySet().forEach(entry -> {
            try {
                Files.write(Paths.get("./src/main/webapp").resolve(entry.getKey()).resolve(Paths.get("index.info")), entry.getValue().toString().getBytes());
            } catch (IOException ex) {
                Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        });
    }
}
