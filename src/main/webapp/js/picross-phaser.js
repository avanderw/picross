/* global Phaser, Picross */

var game = new Phaser.Game(800, 600, Phaser.AUTO, '', {preload: preload, create: create, update: update});

function preload() {
    game.load.image('test', 'levels/test.png');
}

var levelPng;
var y, x;
var rect;
function create() {
    levelPng = game.make.bitmapData(11, 11);
    levelPng.copy('test');
    levelPng.update();

    let matrix = createMatrix(levelPng.height, levelPng.width);
    let group = game.add.group();
    for (y = 0; y < levelPng.height; y++) {
        for (x = 0; x < levelPng.width; x++) {
            var bg = game.make.bitmapData(16, 16);
            ({r, g, b, a} = levelPng.getPixel(x, y));
            bg.fill(r, g, b, a);
            group.create(0, 0, bg);

            matrix[y][x] = levelPng.getPixel(x, y);
        }
    }
    group.align(11, 11, 18, 18);

    group.x = 50;
    group.y = 50;

    let engine = new Picross.Engine(matrix);
    engine.rowHint(0);
    engine.rowHint(5);
    engine.rowHint(9);
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