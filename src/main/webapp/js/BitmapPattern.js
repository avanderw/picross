/* global game */

BitmapPattern = {
    create: function (pattern, colors) {
        let pttrn;
        let clrs;
        switch (arguments.length) {
            case 1:
                pttrn = pattern.pattern;
                clrs = pattern.colors;
                break;
            case 2:
                pttrn = pattern;
                clrs = colors;
                break;
            default:
                throw 'incorrect argument count';

        }

        let wdth = pttrn[0].length;
        let hght = pttrn.length;
        let bmd = game.make.bitmapData(wdth, hght);

        for (let y = 0; y < hght; y++) {
            for (let x = 0; x < wdth; x++) {
                bmd.setPixel32(x, y, clrs[pttrn[y][x]]);
            }
        }
        return bmd;
    },
    HORIZONTAL: {
        pattern: [
            [1],
            [0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    VERTICAL: {
        pattern: [
            [1, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    DIAGONAL_3X3: {
        pattern: [
            [1, 0, 0],
            [0, 0, 1],
            [0, 1, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    DIAGONAL_4X4: {
        pattern: [
            [0, 1, 0, 0],
            [1, 0, 0, 0],
            [0, 0, 0, 1],
            [0, 0, 1, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    STAR_5x5: {
        pattern: [
            [0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0],
            [0, 1, 0, 1, 0],
            [0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    SQUARE_5x5: {
        pattern: [
            [0, 1, 0, 1, 0],
            [1, 1, 0, 1, 1],
            [0, 0, 0, 0, 0],
            [1, 1, 0, 1, 1],
            [0, 1, 0, 1, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    CIRCLE_5x5: {
        pattern: [
            [0, 0, 1, 0, 0],
            [0, 1, 0, 1, 0],
            [1, 0, 0, 0, 1],
            [0, 1, 0, 1, 0],
            [0, 0, 1, 0, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    WAVE_5x5: {
        pattern: [
            [0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0],
            [1, 0, 0, 0, 0]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    GRID_5x5: {
        pattern: [
            [1, 0, 0, 0, 1],
            [0, 1, 0, 1, 0],
            [0, 0, 1, 0, 0],
            [0, 1, 0, 1, 0],
            [1, 0, 0, 0, 1]
        ],
        colors: [0xFF000000, 0xFFFFFFFF]
    },
    DIAG_LIGHT_RIGHT_4x4: {
        pattern: [
            [3, 4, 5, 6],
            [2, 3, 4, 5],
            [1, 2, 3, 4],
            [0, 1, 2, 3]
        ],
        colors: [0xFF121212, 0xFF3e3e3e, 0xFF696969, 0xFFc0c0c0, 0xFFe0e0e0, 0xFFefefef, 0xFFffffff]
    },
    DIAG_LIGHT_LEFT_4x4: {
        pattern: [
            [6, 5, 4, 3],
            [5, 4, 3, 2],
            [4, 3, 2, 1],
            [3, 2, 1, 0]
        ],
        colors: [0xFF121212, 0xFF3e3e3e, 0xFF696969, 0xFFc0c0c0, 0xFFe0e0e0, 0xFFefefef, 0xFFffffff]
    },
    LIGHT_TOP_4x4: {
        pattern: [
            [0, 4, 4, 0],
            [1, 5, 5, 1],
            [2, 6, 6, 2],
            [3, 7, 7, 3]
        ],
        colors: [0xFFf4f4f4, 0xFFdfdfdf, 0xFFc9c9c9, 0xFF9f9f9f, 0xFFffffff, 0xFFeaeaea, 0xFFbebebe, 0xFF6a6a6a]
    },
    LIGHT_4x4: {
        pattern: [
            [0, 2, 2, 3],
            [1, 3, 3, 3],
            [1, 0, 0, 3],
            [1, 1, 1, 0]
        ],
        colors: [0xFF7f7f7f, 0xFF404040, 0xFFbfbfbf, 0xFFFFFFFF]
    }
};