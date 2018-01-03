/* global Picross, objectHash, game */

Picross.BoardController = function (bmpData, colorController, hintController) {
    this.createModel(bmpData);
    this.createView(bmpData, colorController, hintController);
};

Picross.BoardController.prototype = {
    constructor: Picross.BoardController,
    model: {
        drawing: false
    },
    view: {},
    createModel: function (bmpData) {
        this.model.input = createMatrix(bmpData.height, bmpData.width);
    },
    createView: function (bmpData, colorController, hintController) {
        let group = game.add.group();
        group.inputEnableChildren = true;
        let ref = this;
        for (let y = 0; y < bmpData.height; y++) {
            for (let x = 0; x < bmpData.width; x++) {
                let key = objectHash.MD5(bmpData.getPixelRGB(x, y));
                let sprite = game.add.sprite(0, 0, colorController.model[key].texture);
                sprite.col = x;
                sprite.row = y;
                sprite.alpha = 0;
                sprite.inputEnabled = true;
                group.add(sprite);
            }
        }

        group.onChildInputDown.add(function (sprite) {
            this.model.drawing = true;

            sprite.alpha = 1;
            sprite.loadTexture(colorController.selected.texture);
            this.model.input[sprite.row][sprite.col] = colorController.selected.color;
            hintController.updateView(bmpData, ref.model.input, sprite.col, sprite.row);
        }, this);
        group.onChildInputOver.add(function (sprite) {
            if (this.model.drawing) {
                sprite.alpha = 1;
                sprite.loadTexture(colorController.selected.texture);
                this.model.input[sprite.row][sprite.col] = colorController.selected.color;
                hintController.updateView(bmpData, ref.model.input, sprite.col, sprite.row);
            }
        }, this);
        group.onChildInputUp.add(function (sprite) {
            this.model.drawing = false;
        }, this);
        this.view = group;
    }

};