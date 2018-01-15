/* global avdw */

if (typeof avdw === 'undefined') {
    avdw = {};
}

avdw.Memento = function (state, changeSignal) {
    this.state = state;
    this.history = ["dkfjdk"];
    changeSignal.subscribe(this.onChange, this);
};

avdw.Memento.prototype = {

    save: function () {
        console.log('serializing state');
        return Object.assign({}, this.state);
    },
    restore: function (memento) {
        console.log('deserializing state');
        Object.assign(this.state, memento);
    },
    onChange: function (payload, context) {
        if (arguments.length === 2) {
        console.log('saving state');
        console.log(payload);
        console.log(context);
        console.log(context.history);
        context.history.push(context.save());
    } else {

        console.log('saving state');
        console.log(payload);
        console.log(this);
        console.log(this.history);
        this.history.push(this.save());
    }
    },
    undo: function () {
        console.log('restoring previous state');
        let memento = this.history.pop();
        this.restore.call(this, memento);
    }
};

(function () {
    console.log('\nTESTING: Memento.js');
    let state = {a: 0, b: 1};
    let signal = new avdw.Signal("signal{state-change}");
    let memento = new avdw.Memento(state, signal);
    memento.onChange("payload");
    signal.fire('update');
    memento.undo();
})();
