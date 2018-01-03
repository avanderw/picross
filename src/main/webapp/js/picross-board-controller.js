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
        for (let y = 0; y < bmpData.height; y++) {
            for (let x = 0; x < bmpData.width; x++) {
                let sprite = game.add.sprite(0, 0, colorController.model.eraser.texture);
                this.model.input[y][x] = colorController.model.eraser.color;
                sprite.col = x;
                sprite.row = y;
                sprite.alpha = 0;
                sprite.inputEnabled = true;
                group.add(sprite);
            }
        }

        group.onChildInputDown.add(function (sprite) {
            this.model.drawing = true;

            this.fill(sprite, colorController.selected, hintController);
        }, this);
        group.onChildInputOver.add(function (sprite) {
            if (this.model.drawing && (this.model.input[sprite.row][sprite.col] === colorController.model.eraser.color || colorController.selected === colorController.model.eraser)) {
                this.fill(sprite, colorController.selected, hintController);
            }
        }, this);
        group.onChildInputUp.add(function (sprite) {
            this.model.drawing = false;
        }, this);
        this.view = group;
    },
    fill: function (sprite, color, hintController) {
        sprite.alpha = 1;
        sprite.loadTexture(color.texture);
        this.model.input[sprite.row][sprite.col] = color.color;
        hintController.updateView(this.model.input, sprite.col, sprite.row);
    }

};