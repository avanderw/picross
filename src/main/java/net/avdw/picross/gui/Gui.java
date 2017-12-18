/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.gui;

import net.avdw.picross.core.Core;

/**
 *
 * @author van der Westhuizen
 */
public class Gui {

    final Core core;

    public Gui(Core core) {
        this.core = core;
    }

    public void start() {
        Console console = new Console(this);
        console.start();
    }

}
