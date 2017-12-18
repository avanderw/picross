/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.core.level;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import javax.imageio.ImageIO;
import net.avdw.picross.api.ACell;
import org.pmw.tinylog.Logger;

/**
 *
 * @author van der Westhuizen
 */
public class Loader {

    Level.Data load(Path level) {
        Logger.info(String.format("loading %s", level.toAbsolutePath()));
        BufferedImage image = null;
        try {
            image = ImageIO.read(level.toFile());
        } catch (IOException ex) {
            Logger.error(ex);
        }

        List<List<ACell>> grid = new ArrayList();
        List<Color> colors = new ArrayList();
        for (int y = 0; y < image.getHeight(); y++) {
            List<ACell> row = new ArrayList();
            for (int x = 0; x < image.getWidth(); x++) {
                Color color = new Color(image.getRGB(x, y));
                if (!colors.contains(color)) {
                    colors.add(color);
                }
                row.add(new Level.Cell(x, y, color));
            }
            grid.add(row);
        }

        Level.Data levelData = new Level.Data();
        levelData.grid(grid);
        levelData.colors(colors);
        return levelData;
    }

}
