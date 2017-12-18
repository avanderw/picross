/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.gui;

import java.awt.Color;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import net.avdw.picross.api.ACell;
import net.avdw.picross.level.Hint;

/**
 *
 * @author van der Westhuizen
 */
public class Console {

    private final Gui gui;

    Console(Gui gui) {
        this.gui = gui;
    }

    void start() {
        render();

    }

    private void render() {
        StringBuilder builder = new StringBuilder();
        builder.append(String.format("%20s", ""));
        gui.core.level.data().colHints().forEach((col)-> {
            builder.append(String.format("%20s", col));
        });
        builder.append("\n");

        for (int y = 0; y < gui.core.level.data().grid().length; y++) {
            builder.append(String.format("%20s",gui.core.level.data().rowHints().get(y)));
            for (int x = 0; x < gui.core.level.data().grid()[y].length; x++) {
                builder.append(String.format("%20s",gui.core.level.data().grid()[y][x]));
            }
            builder.append("\n");
        }

        System.out.println(builder.toString());
    }

}
