if (typeof avdw === 'undefined') {
    avdw = {};
}
avdw.Signal = function (name) {
    this.name = name;
    this.listeners = [];
};
avdw.Signal.prototype = {
    subscribe: function (consumer, context) {
        console.log("subscribing to", this.name, context);
        this.listeners.push({consumer:consumer, context:context});
    },
    unsubscribe: function (consumer, context) {
        console.log("unsubscribing from", this.name);
        let idx = this.listeners.indexOf({consumer: consumer, context: context});
        if (idx > -1) {
            this.listeners.splice(idx, 1);
        }
    },
    fire: function (payload) {
        console.log("firing", this.name);
        this.listeners.forEach(function (listener) {
            listener.consumer(payload, listener.context);
        });
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
