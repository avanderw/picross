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

let levelBmpData;
function start() {
    levelBmpData = game.make.bitmapData(width, height);
    levelBmpData.copy('test');
    levelBmpData.update();

    let colorController = new Picross.ColorController(levelBmpData, Picross.Constants.cell.size);
    let hintController = new Picross.HintController(levelBmpData, colorController);
    let boardController = new Picross.BoardController(levelBmpData, colorController, hintController);

    boardController.view.align(width, height, Picross.Constants.cell.align, Picross.Constants.cell.align);
    hintController.view.row.alignTo(boardController.view.getBounds(game.stage), Phaser.RIGHT_TOP);
    hintController.view.col.alignTo(boardController.view.getBounds(game.stage), Phaser.TOP_LEFT);

    let picrossGroup = game.add.group();
    picrossGroup.add(boardController.view);
    picrossGroup.add(hintController.view.row);
    picrossGroup.add(hintController.view.col);
    picrossGroup.x -= picrossGroup.getBounds(game.stage).x;
    picrossGroup.y -= picrossGroup.getBounds(game.stage).y;

    colorController.view.alignTo(picrossGroup, Phaser.BOTTOM_CENTER);
    colorController.view.y += Picross.Constants.cell.size;

    game.create.grid("grid", Picross.Constants.cell.align * width, Picross.Constants.cell.align * height, Picross.Constants.cell.align, Picross.Constants.cell.align, "rgba(255,255,255,0.8)", true, function () {
        let grid = game.add.sprite(0, 0, "grid");
        grid.x = boardController.view.x;
        grid.y = boardController.view.y;
        picrossGroup.add(grid);
    });
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