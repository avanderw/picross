/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.level;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.imageio.ImageIO;
import net.avdw.picross.api.ACell;
import net.avdw.picross.api.AHint;
import org.pmw.tinylog.Logger;

/**
 *
 * @author van der Westhuizen
 */
public class Loader {

    Level.Data load(Path level) {
        Logger.info(String.format("loading %s", level.toAbsolutePath()));
        BufferedImage img = null;
        try {
            img = ImageIO.read(level.toFile());
        } catch (IOException ex) {
            Logger.error(ex);
        }

        ACell[][] grid = new ACell[img.getHeight()][img.getWidth()];
        List<Color> colors = new ArrayList();
        for (int y = 0; y < img.getHeight(); y++) {
            for (int x = 0; x < img.getWidth(); x++) {
                Color color = new Color(img.getRGB(x, y));
                if (!colors.contains(color)) {
                    colors.add(color);
                }
                grid[y][x] = new Level.Cell(x, y, color);
            }
        }

        Level.Data levelData = new Level.Data();
        levelData.grid(grid);
        levelData.colors(colors);

        List<List<AHint>> rowHints = new ArrayList();
        for (int y = 0; y < img.getHeight(); y++) {
            Map<Color, Hint> hints = new HashMap();
            for (int x = 0; x < img.getWidth(); x++) {
                if (!hints.containsKey(grid[y][x].color())) {
                    hints.put(grid[y][x].color(), new Hint(grid[y][x].color()));
                }

                hints.get(grid[y][x].color()).unbroken = hints.get(grid[y][x].color()).unbroken() && Math.abs(hints.get(grid[y][x].color()).last - x) < 2;
                hints.get(grid[y][x].color()).last = x;
                hints.get(grid[y][x].color()).count++;
            }
            List<AHint> row = new ArrayList();
            row.addAll(hints.values());
            rowHints.add(row);
        }
        levelData.rowHints(rowHints);

        List<List<AHint>> colHints = new ArrayList();
        for (int x = 0; x < img.getWidth(); x++) {
            Map<Color, Hint> hints = new HashMap();
            for (int y = 0; y < img.getHeight(); y++) {
                if (!hints.containsKey(grid[y][x].color())) {
                    hints.put(grid[y][x].color(), new Hint(grid[y][x].color()));
                }

                hints.get(grid[y][x].color()).unbroken = hints.get(grid[y][x].color()).unbroken() && Math.abs(hints.get(grid[y][x].color()).last - y) < 2;
                hints.get(grid[y][x].color()).last = y;
                hints.get(grid[y][x].color()).count++;
            }
            List<AHint> col = new ArrayList();
            col.addAll(hints.values());
            colHints.add(col);
        }
        levelData.colHints(colHints);

        return levelData;
    }

}
