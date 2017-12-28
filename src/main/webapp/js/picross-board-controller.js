/* global Picross, objectHash, game */

Picross.BoardController = function (bmpData, colorController, hintController) {
    this.createModel(bmpData);
    this.createView(bmpData, colorController, hintController);
};

Picross.BoardController.prototype = {
    constructor: Picross.BoardController,
    model: {},
    view: {},
    createModel: function (bmpData) {
        this.model.input = createMatrix(bmpData.height, bmpData.width);
    },
    createView: function (bmpData, colorController, hintController) {
        let group = game.add.group();
        let ref = this;
        for (let y = 0; y < bmpData.height; y++) {
            for (let x = 0; x < bmpData.width; x++) {
                let key = objectHash.MD5(bmpData.getPixelRGB(x, y));
                let sprite = game.add.sprite(0, 0, colorController.model[key].texture);
                sprite.col = x;
                sprite.row = y;
                sprite.events.onInputDown.add(function () {
                    sprite.alpha = 1;
                    sprite.loadTexture(colorController.selected.texture);
                    this.model.input[sprite.row][sprite.col] = colorController.selected.color;
                    hintController.updateView(bmpData, ref.model.input, sprite.col, sprite.row);
                }, this);
                sprite.alpha = 0;
                sprite.inputEnabled = true;
                group.add(sprite);
            }
        }
        this.view = group;
    }
};