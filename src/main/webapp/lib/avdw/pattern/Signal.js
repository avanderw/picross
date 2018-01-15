/* global objectHash */

if (typeof avdw === 'undefined') {
    avdw = {};
}
avdw.Signal = function (name) {
    this.name = name;
    this.listeners = {};
};
avdw.Signal.prototype = {
    subscribe: function (consumer, context) {
        let listener = {consumer:consumer, context:context};
        let key = objectHash.MD5(listener);
        this.listeners[key] = listener;

        console.log(key, 'subscribed to', this.name);
    },
    unsubscribe: function (consumer, context) {
        let listener = {consumer:consumer, context:context};
        let key = objectHash.MD5(listener);

        if (key in this.listeners) {
            delete this.listeners[key];
        }
        console.log(key, "unsubscribed from", this.name);
    },
    fire: function (payload) {
        console.log("firing", this.name);
        Object.keys(this.listeners).forEach(function (key) {
            this.listeners[key].consumer(payload, this.listeners[key].context);
        }, this);
    }
};


(function () {
    console.log('\nTESTING: Signal.js');

    let named = function (payload) {
        console.log(payload);
    };

    let signal = new avdw.Signal('signal');
    signal.subscribe(function (payload) {
        console.log(payload);
    });
    signal.subscribe(named);
    signal.fire('payload1');
    signal.fire('payload2');
    signal.unsubscribe(function () {
        // do nothing
    });
    signal.fire('payload3');
    signal.unsubscribe(named);
    signal.fire('payload4');
})();
