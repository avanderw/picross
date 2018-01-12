
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

public class GenerateInfoFiles {

    public static void main(String[] args) throws IOException {
        DirectoryInfo info = directoryHandler(Paths.get("./src/main/webapp/levels"));
        Files.write(Paths.get("./src/main/webapp").resolve(Paths.get("level.json")), info.toString().getBytes());
    }

    static public DirectoryInfo directoryHandler(Path directory) throws IOException {
        DirectoryInfo info = new DirectoryInfo(directory.subpath(4, directory.getNameCount()).toString().replace("\\", "/"));

        Files.newDirectoryStream(directory, path -> path.toFile().isDirectory()).forEach(path -> {
            try {
                info.add(directoryHandler(path));
            } catch (IOException ex) {
                Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        });

        Files.newDirectoryStream(directory, path -> path.toFile().isFile() && path.toString().endsWith(".png")).forEach(path -> {
            try {
                info.add(levelHandler(path));
            } catch (IOException ex) {
                Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        });

        return info;
    }

    static public LevelInfo levelHandler(Path path) throws IOException {
        LevelInfo info = new LevelInfo(path.subpath(4, path.getNameCount()).toString().replace("\\", "/"));
        BufferedImage img = ImageIO.read(path.toFile());
        info.width = img.getWidth();
        info.height = img.getHeight();
        return info;
    }
}
