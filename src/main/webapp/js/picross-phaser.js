/* global Phaser, Picross */

var game = new Phaser.Game(800, 600, Phaser.AUTO, '', {preload: preload, create: create, update: update});

function preload() {
    game.load.image('test', 'levels/test.png');
}

let levelPng;
function create() {
    levelPng = game.make.bitmapData(11, 11);
    levelPng.copy('test');
    levelPng.update();

    let matrix = createMatrix(levelPng.height, levelPng.width);
    let cellGroup = game.add.group();
    for (let y = 0; y < levelPng.height; y++) {
        for (let x = 0; x < levelPng.width; x++) {
            var bg = game.make.bitmapData(16, 16);
            ({r, g, b, a} = levelPng.getPixel(x, y));
            bg.fill(r, g, b, a);
            cellGroup.create(0, 0, bg);

            matrix[y][x] = levelPng.getPixelRGB(x, y);
        }
    }
    cellGroup.align(11, 11, 18, 18);
    cellGroup.x = 300 - cellGroup.getBounds().centerX;
    cellGroup.y = 50;

    let engine = new Picross.Engine(matrix);

    var rowHintGroup = game.add.group();
    for (let y = 0; y < levelPng.height; y++) {
        let hint = engine.rowHint(y);
        let hintGroup = game.add.group();

        Object.keys(hint).forEach(function (key, idx) {
            let text = game.add.text(0, 0, hint[key].count, {font: "bold 16px Georgia", fill: hint[key].color.rgba, align: "center"});
            hintGroup.add(text);
        });

        hintGroup.align(5, -1, 18, 0);
        rowHintGroup.add(hintGroup);
    }

    rowHintGroup.align(-1, 11, 0, 18);
    rowHintGroup.alignTo(cellGroup.getBounds(game.stage), Phaser.RIGHT_TOP);
    rowHintGroup.x+=5;
    rowHintGroup.y-=2;


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