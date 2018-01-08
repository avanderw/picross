
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
        version2();
    }

    private static void version2() throws IOException {
        Map<Path, List<Path>> index = new HashMap();
        Files.walk(Paths.get("./src/main/webapp/levels")).forEach(path -> {
            int end = (Files.isDirectory(path)) ? 0 : 1;

            index.putIfAbsent(path.subpath(4, path.getNameCount() - end), new ArrayList());
            if (!Files.isDirectory(path)) {
                index.get(path.subpath(4, path.getNameCount() - end)).add(path.subpath(path.getNameCount() - end, path.getNameCount()));
            } 

        });
        System.out.println(index);
        index.keySet().forEach(path -> {
            try {
                StringBuilder sb = new StringBuilder();
                index.get(path).forEach(filename -> {
                    try {
                        BufferedImage img = ImageIO.read(Paths.get("./src/main/webapp/" + path + "/" + filename).toFile());
                        if (img != null) {
                            sb.append(filename)
                                    .append(":")
                                    .append(img.getWidth())
                                    .append(":")
                                    .append(img.getHeight())
                                    .append("\n");
                        } else {
                            sb.append(filename)
                                    .append("\n");
                        }
                    } catch (IOException ex) {
                        Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
                    }
                });
                Files.write(Paths.get("./src/main/webapp").resolve(path.resolve(Paths.get("index.info"))), sb.toString().getBytes());
                System.out.println(Paths.get("./src/main/webapp").resolve(path.resolve(Paths.get("index.info"))));
                System.out.println(sb);
            } catch (IOException ex) {
                Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        });
    }

    private static void version1() throws IOException {
        StringBuilder sb = new StringBuilder();
        Pattern left = Pattern.compile(".*(\\d+)x.*");
        Pattern right = Pattern.compile(".*x(\\d+).*");
        Files.list(Paths.get("./src/main/webapp/levels")).filter(path -> path.toString().endsWith(".png")).forEach(path -> {
            try {
                BufferedImage img = ImageIO.read(path.toFile());
                sb.append("levels/")
                        .append(path.getName(5))
                        .append(":")
                        .append(img.getWidth())
                        .append(":")
                        .append(img.getHeight())
                        .append("\n");
            } catch (IOException ex) {
                Logger.getLogger(GenerateInfoFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        });
        if (sb.length() > 1) {
            sb.delete(sb.length() - 1, sb.length());
        }
        Files.write(Paths.get("./src/main/webapp/levels/index.info"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }
}
