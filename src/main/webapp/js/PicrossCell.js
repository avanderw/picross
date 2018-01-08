/* global Picross, game */

Picross.CellBuilder = {};
Picross.CellBuilder.create = function (size) {
    let gfx = game.add.graphics();
    gfx.beginFill(0xe6e6e6);
    gfx.drawRect(0, 0, size, size);
    gfx.endFill();

    let sprite = game.add.sprite(0, 0, gfx.generateTexture());
    gfx.destroy();

    return sprite;
};