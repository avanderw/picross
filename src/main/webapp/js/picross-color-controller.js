/* global Picross, objectHash, game */

Picross.ColorController = function (bmpData, textureSize) {
    this.createModel(bmpData, textureSize);
    this.createView(textureSize);
};
Picross.ColorController.prototype = {
    constructor: Picross.ColorController,
    model: {},
    view: {},
    selected: {},
    createModel: function (bmpData, textureSize) {
        for (let y = 0; y < bmpData.height; y++) {
            for (let x = 0; x < bmpData.width; x++) {
                let color = bmpData.getPixelRGB(x, y);
                let key = objectHash.MD5(color);
                if (!(key in this.model)) {
                    let texture = game.make.bitmapData(textureSize, textureSize);
                    texture.fill(color.r, color.g, color.b, color.a);
                    this.model[key] = {key: key, color: color, texture: texture};
                }
            }
        }

        let ref = this.model;
        Object.keys(this.model).forEach(function (key, idx) {
            ref[key].idx = idx;
        });
    },
    createView: function (textureSize) {
        this.view = game.add.group();
        let ref = this;
        Object.keys(this.model).forEach(function (key) {
            let bg = game.make.bitmapData(textureSize * 2, textureSize * 2);
            ({r, g, b, a} = ref.model[key].color);
            bg.fill(r, g, b, a);

            let sprite = game.add.sprite(0, 0, bg);
            sprite.events.onInputDown.add(function () {
                ref.select(key);
            });
            sprite.inputEnabled = true;
            ref.view.add(sprite);
        });
        this.view.align(-1, 1, textureSize * 2 + 2, textureSize * 2 + 2);
    },
    select: function (key) {
        this.selected = this.model[key];
    }
};
