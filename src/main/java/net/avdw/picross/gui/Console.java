/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.gui;

import java.util.List;
import net.avdw.picross.api.ACell;

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
        for (List<ACell> row : gui.core.level.data().grid()) {
            for (ACell cell : row) {
                builder.append(cell);
            }
            builder.append(Character.LINE_SEPARATOR);
        }

        System.out.println(builder.toString());
    }

}
