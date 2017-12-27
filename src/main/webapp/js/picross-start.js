/* global Phaser, Picross, objectHash */

var game = new Phaser.Game(800, 600, Phaser.AUTO, '', {preload: preload, create: create, update: update});

function preload() {
    game.load.text("idx", "levels/index.info");
}

let width;
let height;
function create() {
    let files = game.cache.getText("idx").split("\n");
    let rnd = game.rnd.integerInRange(0, files.length - 1);
    let file = files[rnd].split(":");
    width = file[1];
    height = file[2];

    game.load.onLoadComplete.add(start, this);
    game.load.image("test", file[0]);
    game.load.start();
}

let levelPng;
let colorController;
let hintController;
function start() {
    levelPng = game.make.bitmapData(width, height);
    levelPng.copy('test');
    levelPng.update();

    colorController = new Picross.ColorController(levelPng, Picross.Constants.cell.size);
    hintController = new Picross.HintController(levelPng, colorController);

    let pngData = createMatrix(levelPng.height, levelPng.width);
    let inputData = createMatrix(levelPng.height, levelPng.width);
    let colorMap = {};
    let picGroup = game.add.group();
    for (let y = 0; y < levelPng.height; y++) {
        for (let x = 0; x < levelPng.width; x++) {
            let bg = game.make.bitmapData(Picross.Constants.cell.size, Picross.Constants.cell.size);
            let color = levelPng.getPixelRGB(x, y);
            let key = objectHash.MD5(color);
            bg.fill(color.r, color.g, color.b, color.a);
            let sprite = game.add.sprite(0, 0, bg);
            sprite.inputEnabled = true;
            sprite.cellY = y;
            sprite.cellX = x;
            sprite.events.onInputDown.add(function () {
                sprite.alpha = 1;
                sprite.loadTexture(colorController.selected.texture);
                inputData[y][x] = colorController.selected.color;
            }, this);
            sprite.alpha = 0;
            picGroup.add(sprite);
            colorMap[key] = {color: color, texture: bg};
            pngData[y][x] = color;
        }
    }
    picGroup.align(width, height, Picross.Constants.cell.align, Picross.Constants.cell.align);

    hintController.view.row.alignTo(picGroup.getBounds(game.stage), Phaser.RIGHT_TOP);
    hintController.view.row.x += Picross.Constants.text.shift;

    hintController.view.col.alignTo(picGroup.getBounds(game.stage), Phaser.TOP_LEFT);
    hintController.view.col.x += Picross.Constants.text.shift;

    let picrossGroup = game.add.group();
    picrossGroup.add(picGroup);
    picrossGroup.add(hintController.view.row);
    picrossGroup.add(hintController.view.col);
    picrossGroup.x -= picrossGroup.getBounds(game.stage).x;
    picrossGroup.y -= picrossGroup.getBounds(game.stage).y;

    colorController.view.alignTo(picrossGroup, Phaser.BOTTOM_CENTER);
    colorController.view.y += Picross.Constants.cell.size;
}

function update() {
}

function createMatrix(size) {
    let matrix = new Array(size || 0),
            i = size;
    if (arguments.length > 1) {
        let args = Array.prototype.slice.call(arguments, 1);
        while (i--) {
            matrix[size - 1 - i] = createMatrix.apply(this, args);
        }
    }

    return matrix;
}