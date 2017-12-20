package net.avdw.picross.level

import java.awt.Color
import java.awt.image.BufferedImage
import java.io.IOException
import java.nio.file.Path
import java.util.ArrayList
import java.util.HashMap
import javax.imageio.ImageIO
import net.avdw.picross.api.ACell
import net.avdw.picross.api.AHint
import org.pmw.tinylog.Logger

class Loader {

    internal fun load(level: Path): Level.Data {
        Logger.info(String.format("loading %s", level.toAbsolutePath()))
        var img: BufferedImage? =  ImageIO.read(level.toFile())

        val grid = Array<Array<ACell>>(img!!.height) { arrayOfNulls(img.width) }
        val colors = ArrayList()
        for (y in 0 until img.height) {
            for (x in 0 until img.width) {
                val color = Color(img.getRGB(x, y))
                if (!colors.contains(color)) {
                    colors.add(color)
                }
                grid[y][x] = Level.Cell(x, y, color)
            }
        }

        val levelData = Level.Data()
        levelData.grid(grid)
        levelData.colors(colors)

        val rowHints = ArrayList()
        for (y in 0 until img.height) {
            val hints = HashMap()
            for (x in 0 until img.width) {
                if (!hints.containsKey(grid[y][x].color())) {
                    hints.put(grid[y][x].color(), Hint(grid[y][x].color()))
                }

                hints.get(grid[y][x].color()).unbroken = hints.get(grid[y][x].color()).unbroken()!! && Math.abs(hints.get(grid[y][x].color()).last - x) < 2
                hints.get(grid[y][x].color()).last = x
                hints.get(grid[y][x].color()).count++
            }
            val row = ArrayList()
            row.addAll(hints.values)
            rowHints.add(row)
        }
        levelData.rowHints(rowHints)

        val colHints = ArrayList()
        for (x in 0 until img.width) {
            val hints = HashMap()
            for (y in 0 until img.height) {
                if (!hints.containsKey(grid[y][x].color())) {
                    hints.put(grid[y][x].color(), Hint(grid[y][x].color()))
                }

                hints.get(grid[y][x].color()).unbroken = hints.get(grid[y][x].color()).unbroken()!! && Math.abs(hints.get(grid[y][x].color()).last - y) < 2
                hints.get(grid[y][x].color()).last = y
                hints.get(grid[y][x].color()).count++
            }
            val col = ArrayList()
            col.addAll(hints.values)
            colHints.add(col)
        }
        levelData.colHints(colHints)

        return levelData
    }

}
