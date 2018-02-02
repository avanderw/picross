
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.CopyOption;
import java.nio.file.FileAlreadyExistsException;
import java.nio.file.FileSystemLoopException;
import java.nio.file.FileVisitOption;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;
import java.util.EnumSet;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

public class GenerateInfoFiles {

    public static void main(String[] args) throws IOException {
        DirectoryInfo info = directoryHandler(Paths.get("./src/main/webapp/levels"));
        Files.write(Paths.get("./src/main/webapp").resolve(Paths.get("level.json")), info.toString().getBytes());
        Files.write(Paths.get("./assets/json").resolve(Paths.get("level.json")), info.toString().getBytes());

        EnumSet<FileVisitOption> opts = EnumSet.of(FileVisitOption.FOLLOW_LINKS);
        TreeCopier tc = new TreeCopier(Paths.get("./src/main/webapp/levels"), Paths.get("./assets/levels"));
        Files.walkFileTree(Paths.get("./src/main/webapp/levels"), opts, Integer.MAX_VALUE, tc);
    }

    static public DirectoryInfo directoryHandler(Path directory) throws IOException {
        DirectoryInfo info = new DirectoryInfo(directory.subpath(directory.getNameCount() - 1, directory.getNameCount()).toString().replace("\\", "/"));

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

    static void copyFile(Path source, Path target) {
        CopyOption[] options = new CopyOption[]{StandardCopyOption.COPY_ATTRIBUTES, StandardCopyOption.REPLACE_EXISTING};

        try {
            Files.copy(source, target, options);
        } catch (IOException x) {
            System.err.format("Unable to copy: %s: %s%n", source, x);
        }
    }

    static class TreeCopier implements FileVisitor<Path> {

        private final Path source;
        private final Path target;

        TreeCopier(Path source, Path target) {
            this.source = source;
            this.target = target;
        }

        @Override
        public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) {
            CopyOption[] options = new CopyOption[]{StandardCopyOption.COPY_ATTRIBUTES};

            Path newdir = target.resolve(source.relativize(dir));
            try {
                Files.copy(dir, newdir, options);
            } catch (FileAlreadyExistsException x) {
                // ignore
            } catch (IOException x) {
                System.err.format("Unable to create: %s: %s%n", newdir, x);
                return FileVisitResult.SKIP_SUBTREE;
            }
            return FileVisitResult.CONTINUE;
        }

        @Override
        public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) {
            copyFile(file, target.resolve(source.relativize(file)));
            return FileVisitResult.CONTINUE;
        }

        @Override
        public FileVisitResult postVisitDirectory(Path dir, IOException exc) {
            // fix up modification time of directory when done
            if (exc == null) {
                Path newdir = target.resolve(source.relativize(dir));
                try {
                    FileTime time = Files.getLastModifiedTime(dir);
                    Files.setLastModifiedTime(newdir, time);
                } catch (IOException x) {
                    System.err.format("Unable to copy all attributes to: %s: %s%n", newdir, x);
                }
            }
            return FileVisitResult.CONTINUE;
        }

        @Override
        public FileVisitResult visitFileFailed(Path file, IOException exc) {
            if (exc instanceof FileSystemLoopException) {
                System.err.println("cycle detected: " + file);
            } else {
                System.err.format("Unable to copy: %s: %s%n", file, exc);
            }
            return FileVisitResult.CONTINUE;
        }
    }

}
