/* global Picross, objectHash, game */

Picross.HintController = function (bmpData, colorController) {
    this.colorController = colorController;
    this.createModel(bmpData);
    this.createView();
};

Picross.HintController.prototype = {
    constructor: Picross.HintController,
    model: {
        rows: [],
        cols: []
    },
    view: {
        row: {},
        col: {}
    },
    createModel: function (bmpData) {
        for (let y = 0; y < bmpData.height; y++) {
            let colors = [];
            for (let x = 0; x < bmpData.width; x++) {
                colors.push(bmpData.getPixelRGB(x, y));
            }
            this.model.rows[y] = this.createHint(colors);
        }

        for (let x = 0; x < bmpData.width; x++) {
            let colors = [];
            for (let y = 0; y < bmpData.height; y++) {
                colors.push(bmpData.getPixelRGB(x, y));
            }
            this.model.cols[x] = this.createHint(colors);
        }
    },
    createHint: function (colors) {
        let map = {};
        colors.forEach(function (color, idx) {
            let key = objectHash.MD5(color);
            if (!(key in map)) {
                map[key] = {
                    count: 0,
                    last: idx,
                    broken: false
                };
            }

            map[key].count++;
            if (!map[key].broken) {
                map[key].broken = idx - map[key].last > 1;
            }
            map[key].last = idx;
        });
        return map;
    },
    createView: function () {
        this.view.row = this.createHintView(this.model.rows, false);
        this.view.col = this.createHintView(this.model.cols, true);
    },
    createHintView: function (hints, isVertical) {
        var groups = game.add.group();

        hints.forEach(function (hint, idx) {
            let hintGroup = game.add.group();
            Object.keys(hint).forEach(function (key) {
                let viewGroup = game.add.group();
                hintGroup.add(viewGroup);
                if (!hint[key].broken && hint[key].count !== 1) {
                    let graphics = game.add.graphics(Picross.Constants.cell.align / 2, Picross.Constants.cell.align / 2);
                    graphics.beginFill(0x333333, 1);

                    if (isVertical) {
                        graphics.drawCircle(0, Picross.Constants.cell.align * this.colorController.model.colors[key].idx, Picross.Constants.cell.size);
                    } else {
                        graphics.drawCircle(Picross.Constants.cell.align * this.colorController.model.colors[key].idx, 0, Picross.Constants.cell.size);
                    }
                    viewGroup.add(graphics);
                }
                let style = {font: "bold " + Picross.Constants.text.size + "px Georgia", fill: this.colorController.model.colors[key].color.rgba, boundsAlignH: "center", boundsAlignV: "middle"};

                let text = isVertical
                        ? game.add.text(0, Picross.Constants.cell.align * this.colorController.model.colors[key].idx, hint[key].count, style)
                        : game.add.text(Picross.Constants.cell.align * this.colorController.model.colors[key].idx, 0, hint[key].count, style);
                text.setTextBounds(0, 0, Picross.Constants.cell.align, Picross.Constants.cell.align);

                viewGroup.add(text);
            }, this);

            if (isVertical) {
                hintGroup.x = Picross.Constants.cell.align * idx;
                let bg = game.make.bitmapData(Picross.Constants.cell.size, Picross.Constants.cell.size);
                bg.fill(255, 0, 0, 1);
                let sprite = game.add.sprite(0, -Picross.Constants.cell.align, bg);
                sprite.alpha = 0;
                hintGroup.add(sprite);
            } else {
                hintGroup.y = Picross.Constants.cell.align * idx;
                let bg = game.make.bitmapData(Picross.Constants.cell.size, Picross.Constants.cell.size);
                bg.fill(255, 0, 0, 1);
                let sprite = game.add.sprite(Picross.Constants.cell.align * Object.keys(this.colorController.model.colors).length, 0, bg);
                sprite.alpha = 0;
                hintGroup.add(sprite);
            }
            groups.add(hintGroup);
        }, this);
        return groups;
    },
    updateView: function (input, col, row) {
        if (input[row][col] === undefined) {
            return;
        }

        let inputKey = objectHash.MD5(input[row][col]);
        let rowError = !Object.keys(this.model.rows[row]).includes(inputKey);
        let colError = !Object.keys(this.model.cols[col]).includes(inputKey);

        if (!rowError) {
            for (let x = 0; x < input[row].length; x++) {
                if (input[row][x] !== this.colorController.model.eraser.color && !rowError) {
                    rowError = !Object.keys(this.model.rows[row]).includes(objectHash.MD5(input[row][x]));
                }
            }
        }

        if (!rowError) {
            Object.keys(this.model.rows[row]).forEach(function (key, idx) {
                let hint = this.model.rows[row][key];
                let count = 0;
                if (!rowError) {
                    for (let x = 0; x < input[row].length; x++) {
                        if (input[row][x] !== undefined && objectHash.MD5(input[row][x]) === key) {
                            count++;
                        }
                    }

                    rowError = (hint.count < count);
                }

                if (!rowError) {
                    if (hint.count === count) {
                        hint.last = -1;
                        let nowBroken = false;
                        for (let x = 0; x < input[row].length; x++) {
                            if (input[row][x] !== undefined && objectHash.MD5(input[row][x]) === key) {
                                if (hint.last === -1) {
                                    hint.last = x;
                                }

                                if (!nowBroken) {
                                    nowBroken = x - hint.last > 1;
                                }
                                hint.last = x;
                            }
                        }
                        rowError = hint.broken !== nowBroken;
                    }
                }

                this.view.row.getAt(row).getAt(idx).alpha = (!rowError && hint.count === count) ? 0 : 1;
            }, this);
        }

        if (!colError) {
            for (let y = 0; y < input.length; y++) {
                if (input[y][col] !== this.colorController.model.eraser.color && !colError) {
                    colError = !Object.keys(this.model.cols[col]).includes(objectHash.MD5(input[y][col]));
                }
            }
        }

        if (!colError) {
            Object.keys(this.model.cols[col]).forEach(function (key, idx) {
                let hint = this.model.cols[col][key];
                let count = 0;
                if (!colError) {
                    for (let y = 0; y < input.length; y++) {
                        if (input[y][col] !== undefined && objectHash.MD5(input[y][col]) === key) {
                            count++;
                        }
                    }

                    colError = (hint.count < count);
                }

                if (!colError) {
                    if (hint.count === count) {
                        hint.last = -1;
                        let nowBroken = false;
                        for (let y = 0; y < input.length; y++) {
                            if (input[y][col] !== undefined && objectHash.MD5(input[y][col]) === key) {
                                if (hint.last === -1) {
                                    hint.last = y;
                                }

                                if (!nowBroken) {
                                    nowBroken = y - hint.last > 1;
                                }
                                hint.last = y;
                            }
                        }
                        colError = hint.broken !== nowBroken;
                    }
                }
                this.view.col.getAt(col).getAt(idx).alpha = (!colError && hint.count === count) ? 0 : 1;
            }, this);
        }

        this.view.row.getAt(row).getAt(this.view.row.getAt(row).length - 1).alpha = (rowError) ? 1 : 0;
        this.view.col.getAt(col).getAt(this.view.col.getAt(col).length - 1).alpha = (colError) ? 1 : 0;

    }
};

