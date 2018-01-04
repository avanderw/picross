/* global game, Phaser, PIXI */

GridPattern = {
    create: function (width, height, cellSize, guides = false) {
        let gfx = game.add.graphics(0, 0);

        if (guides) {
            gfx.beginFill(0xe6e6e6);
            gfx.drawRect(0, Math.floor(height * 1 / 4) * cellSize, width * cellSize, cellSize);
//        gfx.drawRect(Math.floor(width * 1 / 4) * cellSize, 0, cellSize, height * cellSize);
            gfx.drawRect(0, Math.floor(height * 3 / 4) * cellSize, width * cellSize, cellSize);
//        gfx.drawRect(Math.floor(width * 3 / 4) * cellSize, 0, cellSize, height * cellSize);
            gfx.endFill();

            gfx.beginFill(0xcccccc);
            gfx.drawRect(0, Math.floor(height / 2) * cellSize, width * cellSize, cellSize);
            gfx.drawRect(Math.floor(width / 2) * cellSize, 0, cellSize, height * cellSize);
            gfx.endFill();
        }

        gfx.lineStyle(1, 0x999999);
        for (let y = 0; y <= height; y++) {
            gfx.moveTo(0, y * cellSize);
            gfx.lineTo(width * cellSize, y * cellSize);
        }

        for (let x = 0; x <= width; x++) {
            gfx.moveTo(x * cellSize, 0);
            gfx.lineTo(x * cellSize, height * cellSize);
        }

        let sprite = game.add.sprite(0, 0, gfx.generateTexture());
        gfx.destroy();

        return sprite;
    }
};