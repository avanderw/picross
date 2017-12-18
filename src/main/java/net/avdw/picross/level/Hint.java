package net.avdw.picross.level;

import java.awt.Color;
import net.avdw.picross.api.AHint;

public class Hint implements AHint {

    private final Color color;
    Integer count;
    int last = 0;
    Boolean unbroken = Boolean.TRUE;

    Hint(Color color) {
        this.color = color;
        this.count = 0;
    }

    @Override
    public Color color() {
        return color;
    }

    @Override
    public Integer count() {
        return count;
    }

    @Override
    public Boolean unbroken() {
        return unbroken;
    }

    @Override
    public String toString(){
        return String.format("%s:%s", count, unbroken ? "t" : "f");
    }
}
