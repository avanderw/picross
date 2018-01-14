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


var MyObject = (function () {

    // Constructor
    function MyObject(foo) {
        this._foo = foo;
    }

    function privateFun(prefix) {
        return prefix + this._foo;
    }

    MyObject.prototype.publicFun = function () {
        return privateFun.call(this, '>>');
    };

    return MyObject;
})();


var myObject = new MyObject('bar');
myObject.publicFun();      // Returns '>>bar'
myObject.privateFun('>>'); // ReferenceError: private is not defined