/* global Phaser */

var game = new Phaser.Game(800, 600, Phaser.AUTO, '', { preload: preload, create: create, update: update });

function preload() {
    game.load.image('test', 'levels/test.png');
}

var bmd;
function create() {
    bmd = game.make.bitmapData(game.world.centerXs, game.world.centerY, 0.5, 0.5, 2, 2);
    bmd.copy('test');
    
    bmd.addToWorld();
}

function update() {
}