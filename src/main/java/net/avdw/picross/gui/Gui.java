/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.gui;

import java.awt.Canvas;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import net.avdw.picross.core.Core;
import org.pmw.tinylog.Configurator;
import org.pmw.tinylog.Level;

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
        showFrame();

        Console console = new Console(this);
        console.start();
    }

    private void showFrame() {
        Configurator.currentConfig()
                .formatPattern("{date:yyyy-MM-dd HH:mm:ss} [{thread}] {class}.{method}() {level}: {message}")
                .level(Level.TRACE)
                .activate();

        Frame frame = new Frame("Picross");
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                frame.dispose();
            }
        });

        frame.setSize(400, 400);
        frame.add(new GuiLayout(this, 16));
        frame.setVisible(true);
        frame.pack();
    }

}
