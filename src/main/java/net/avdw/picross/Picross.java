/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross;

import net.avdw.picross.core.Core;
import net.avdw.picross.gui.Gui;
import org.pmw.tinylog.Configurator;
import org.pmw.tinylog.Level;

/**
 *
 * @author van der Westhuizen
 */
public class Picross {

    public static void main(String[] args) {
        Configurator.currentConfig()
                .formatPattern("{date:yyyy-MM-dd HH:mm:ss} [{thread}] {class}.{method}() {level}: {message}")
                .level(Level.TRACE)
                .activate();

        Picross picross = new Picross();
        picross.start();
    }

    private final Gui gui;
    private final Core core;

    Picross() {
        core = new Core();
        gui = new Gui(core);
    }

    private void start() {
        gui.start();
    }
}
