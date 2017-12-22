/* global Picross, objectHash */
Picross = function () {};

Picross.Engine = function (matrix) {
    this.matrix = matrix;
};

Picross.Engine.prototype = {
    constructor: Picross.Engine,
    rowHint: function (idx, input) {
        let map = {};
        for (let x = 0; x < this.matrix[idx].length; x++) {
            let key = objectHash.MD5(this.matrix[idx][x]);
            if (!(key in map)) {
                map[key] = {
                    color: this.matrix[idx][x],
                    count: 0,
                    last: x,
                    broken: false
                };
            }

            map[key].count++;
            if (!map[key].broken) {
                map[key].broken = x - map[key].last > 1;
            }
            map[key].last = x;
        }
        return map;
    },
    colHint: function (idx, input) {
        for (let y = 0; y < this.matrix.length; y++) {
            this.matrix[y][idx];
        }
    }
};