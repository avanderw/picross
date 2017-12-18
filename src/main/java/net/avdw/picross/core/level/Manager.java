/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.core.level;

import java.nio.file.Paths;
import java.util.List;
import net.avdw.picross.api.ACell;

/**
 *
 * @author van der Westhuizen
 */
public class Manager {

    private final Loader loader;

    Manager() {
        loader = new Loader();

    }

    Level.Data level() {
        return loader.load(Paths.get("./src/main/resources/icon_share.png"));
    }
}
