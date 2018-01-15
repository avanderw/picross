/* global avdw */

if (typeof avdw === 'undefined') {
    avdw = {};
}

avdw.Memento = function (state, changeSignal) {
    this.state = state;
    this.history = [];

    this.save(null, this);
    changeSignal.subscribe(this.save, this);
};

avdw.Memento.prototype = {
    serialize: function () {
        console.log('serializing state');
        return Object.assign({}, this.state);
    },
    deserialize: function (memento) {
        console.log('deserializing state');
        Object.assign(this.state, memento);
    },
    save: function (payload, context) {
        console.log('saving state');
        if (arguments.length < 2) {
            context = this;
        }

        context.history.push(context.serialize());
    },
    restore: function () {
        console.log('restoring state');
        let memento = this.history.pop();
        this.deserialize(memento);
    }
};

(function () {
    console.log('\nTESTING: Memento.js');
    let state = {a: 0};
    let signal = new avdw.Signal("signal{state-change}");
    let memento = new avdw.Memento(state, signal);
    console.log('state', state);

    state.a = 1;
    console.log('state', state);
    signal.fire('update');

    state.a = 2;
    console.log('state', state);
    memento.save("payload");

    state.a = 3;
    console.log('state', state);

    memento.restore();
    console.log('state', state);
    memento.restore();
    console.log('state', state);
})();
