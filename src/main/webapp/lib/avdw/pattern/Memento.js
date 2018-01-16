/* global avdw */

if (typeof avdw === 'undefined') {
    avdw = {};
}

avdw.Memento = class Memento {
    constructor(state) {
        this.state = state;
        this.history = [];
    }
    serialize() {
        console.log('serializing state');
        return Object.assign({}, this.state);
    }

    deserialize(memento) {
        console.log('deserializing state');
        Object.assign(this.state, memento);
    }
    save() {
        console.log('saving state');
        this.history.push(this.serialize());
    }
    restore() {
        console.log('restoring state');
        let memento = this.history.pop();
        this.deserialize(memento);
    }
};

(function () {
    console.log('\nTESTING: Memento.js');
    let state = {a: 0};
    let memento = new avdw.Memento(state);
    console.log('state', state);

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
