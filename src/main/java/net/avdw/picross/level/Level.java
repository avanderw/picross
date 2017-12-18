/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.level;

import java.awt.Color;
import java.util.List;
import java.util.Map;
import net.avdw.picross.api.ACell;
import net.avdw.picross.api.AHint;
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
        ACell[][] grid;
        List<List<AHint>> rowHints;
        List<List<AHint>> colHints;

        Data() {

        }

        void colHints(List<List<AHint>> colHints) {
            this.colHints = colHints;
        }

        @Override
        public List<List<AHint>> colHints() {
            return colHints;
        }

        void colors(List<Color> colors) {
            this.colors = colors;
        }

        void grid(ACell[][] grid) {
            this.grid = grid;
        }

        @Override
        public ACell[][] grid() {
            return grid;
        }

        void rowHints(List<List<AHint>> rowHints) {
            this.rowHints = rowHints;
        }

        @Override
        public List<List<AHint>> rowHints() {
            return rowHints;
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

        @Override
        public Color color() {
            return color;
        }

        @Override
        public String toString() {
            return String.format("r%s,g%s,b%s", color.getRed(), color.getGreen(), color.getBlue());
        }
    }
}
