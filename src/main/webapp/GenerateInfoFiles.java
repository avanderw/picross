
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import javax.imageio.ImageIO;

public class GenerateInfoFiles {

    public static void main(String[] args) throws IOException {
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
