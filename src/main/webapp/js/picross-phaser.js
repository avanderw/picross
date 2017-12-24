/* global Phaser, Picross, objectHash */

var game = new Phaser.Game(800, 600, Phaser.AUTO, '', {preload: preload, create: create, update: update});

function preload() {
    game.load.image('test', 'levels/test.png');
}

let levelPng;
let textSize = 14;
let textShift = textSize / 2;
let cellSize = 24;
let spacing = cellSize + 2;

function create() {
    levelPng = game.make.bitmapData(11, 11);
    levelPng.copy('test');
    levelPng.update();

    let matrix = createMatrix(levelPng.height, levelPng.width);
    let colorMap = {};
    let picGroup = game.add.group();
    for (let y = 0; y < levelPng.height; y++) {
        for (let x = 0; x < levelPng.width; x++) {
            var bg = game.make.bitmapData(cellSize, cellSize);
            let color = levelPng.getPixelRGB(x, y);
            let key = objectHash.MD5(color);

            bg.fill(color.r, color.g, color.b, color.a);
            picGroup.create(0, 0, bg);
            colorMap[key] = {};
            matrix[y][x] = color;
        }
    }
    picGroup.align(11, 11, spacing, spacing);

    let engine = new Picross.Engine(matrix, Object.keys(colorMap));

    var rowHintGroup = game.add.group();
    for (let y = 0; y < levelPng.height; y++) {
        let hint = engine.rowHint(y);
        let hintGroup = game.add.group();

        Object.keys(hint).forEach(function (key, idx) {
            if (!hint[key].broken && hint[key].count !== 1) {
                let graphics = game.add.graphics(spacing / 2, spacing / 2);
                graphics.beginFill(0x333333, 1);
                graphics.drawCircle(spacing * hint[key].idx, 0, cellSize);
                hintGroup.add(graphics);
            }
            let text = game.add.text(spacing * hint[key].idx, 0, hint[key].count, {font: "bold " + textSize + "px Georgia", fill: hint[key].color.rgba, boundsAlignH: "center", boundsAlignV: "middle"});
            text.setTextBounds(0, 0, spacing, spacing);
            hintGroup.add(text);
        });

        hintGroup.y = spacing * y;
        rowHintGroup.add(hintGroup);
    }

    rowHintGroup.alignTo(picGroup.getBounds(game.stage), Phaser.RIGHT_TOP);
    rowHintGroup.x += textShift;

    var colHintGroup = game.add.group();
    for (let x = 0; x < levelPng.width; x++) {
        let hint = engine.colHint(x);
        let hintGroup = game.add.group();

        Object.keys(hint).forEach(function (key, idx) {
            if (!hint[key].broken && hint[key].count !== 1) {
                let graphics = game.add.graphics(spacing / 2, spacing / 2);
                graphics.beginFill(0x333333, 1);
                graphics.drawCircle(0, spacing * hint[key].idx, cellSize);
                hintGroup.add(graphics);
            }
            let text = game.add.text(0, spacing * hint[key].idx, hint[key].count, {font: "bold " + textSize + "px Georgia", fill: hint[key].color.rgba, boundsAlignH: "center", boundsAlignV: "middle"});
            text.setTextBounds(0, 0, spacing, spacing);
            hintGroup.add(text);
        });

        hintGroup.x = spacing * x;
        colHintGroup.add(hintGroup);
    }

    colHintGroup.alignTo(picGroup.getBounds(game.stage), Phaser.TOP_LEFT);
    colHintGroup.x += textShift;

    let picrossGroup = game.add.group();
    picrossGroup.add(picGroup);
    picrossGroup.add(rowHintGroup);
    picrossGroup.add(colHintGroup);

    picrossGroup.x -= picrossGroup.getBounds(game.stage).x;
    picrossGroup.y -= picrossGroup.getBounds(game.stage).y;
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