/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.avdw.picross.api;

import java.awt.Color;

/**
 *
 * @author CP318674
 */
public interface AHint {

    Integer count();

    Color color();

    Boolean unbroken();
}
