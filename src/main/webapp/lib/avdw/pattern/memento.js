/* global avdw */
if (avdw === undefined) {
    avdw = {};
}
avdw.Memento = function (state, changeSignal) {
    this.state = state;
    changeSignal.add(this.onChange);
};

avdw.Memento.prototype = {
    state: undefined,
    history: [],
    save: function () {
        return Object.assign({}, this.state);
    },
    restore: function (memento) {
        Object.assign(this.state, memento);
    },
    undo: function () {
        let memento = this.history.pop();
        this.restore(memento);
    },
    onChange: function () {
        let memento = this.save();
        this.history.push(memento);
    }
};
