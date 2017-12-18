/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.core.level;

import java.awt.Color;
import java.util.List;
import net.avdw.picross.api.ACell;
import net.avdw.picross.api.ALevel;

/**
 *
 * @author van der Westhuizen
 */
public class Level {

    private final Manager manager = new Manager();

    public ALevel data() {
        return manager.level();
    }

    static class Data implements ALevel {

        List<Color> colors;
        List<List<ACell>> grid;

        Data() {

        }

        void colors(List<Color> colors) {
            this.colors = colors;
        }

        void grid(List<List<ACell>> grid) {
            this.grid = grid;
        }

        @Override
        public List<List<ACell>> grid() {
            return grid;
        }
    }

    static class Cell implements ACell {

        final Color color;

        final Integer x;
        final Integer y;

        Cell(Integer x, Integer y, Color color) {
            this.x = x;
            this.y = y;
            this.color = color;
        }

    }
}
