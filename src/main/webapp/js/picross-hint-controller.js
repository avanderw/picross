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
        row:{},
        col:{}
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
    createView:function() {
        this.view.row = this.createHintView(this.model.rows, false);
        this.view.col = this.createHintView(this.model.cols, true);
    },
    createHintView: function (hints, isVertical) {
        var groups = game.add.group();
        var ref = this;
        
        hints.forEach(function (hint, idx) {
            let hintGroup = game.add.group();
            Object.keys(hint).forEach(function (key) {
                if (!hint[key].broken && hint[key].count !== 1) {
                    let graphics = game.add.graphics(Picross.Constants.cell.align / 2, Picross.Constants.cell.align / 2);
                    graphics.beginFill(0x333333, 1);

                    if (isVertical) {
                        graphics.drawCircle(0, Picross.Constants.cell.align * ref.colorController.model[key].idx, Picross.Constants.cell.size);
                    } else {
                        graphics.drawCircle(Picross.Constants.cell.align * ref.colorController.model[key].idx, 0, Picross.Constants.cell.size);
                    }
                    hintGroup.add(graphics);
                }
                let style = {font: "bold " + Picross.Constants.text.size + "px Georgia", fill: ref.colorController.model[key].color.rgba, boundsAlignH: "center", boundsAlignV: "middle"};

                let text = isVertical
                        ? game.add.text(0, Picross.Constants.cell.align * ref.colorController.model[key].idx, hint[key].count, style)
                        : game.add.text(Picross.Constants.cell.align * ref.colorController.model[key].idx, 0, hint[key].count, style);
                text.setTextBounds(0, 0, Picross.Constants.cell.align, Picross.Constants.cell.align);
                hintGroup.add(text);
            });

            if (isVertical) {
                hintGroup.x = Picross.Constants.cell.align * idx;
            } else {
                hintGroup.y = Picross.Constants.cell.align * idx;
            }
            groups.add(hintGroup);

        });
        return groups;
    }
};

