if (typeof avdw === 'undefined') {
    avdw = {};
}
avdw.EventDispatcher = (function () {
    let _listeners = {};

    // Constructor
    function EventDispatcher() {
        for (let i = 0; i < arguments.length; i++) {
            _listeners[arguments[i]] = [];
        }
    }

    // Private

    // Public
    EventDispatcher.prototype.subscribe = function (eventType, consumer) {
        console.log("subscribing to ", eventType);
        _listeners[eventType].push(consumer);
    };

    EventDispatcher.prototype.unsubscribe = function (eventType, consumer) {
        console.log("unsubscribing", eventType);
        if (eventType in _listeners) {
            let idx = _listeners[eventType].indexOf(consumer);
            if (idx > -1) {
                _listeners[eventType].splice(idx, 1);
            }
        }
    };

    EventDispatcher.prototype.fire = function (eventType, payload) {
        console.log("firing", eventType);
        if (eventType in _listeners) {
            _listeners[eventType].forEach(function (listener) {
                listener.call(this, payload);
            }, this);
        }
    };

    return EventDispatcher;
})();

(function () {
    console.log('TESTING: EventDispatcher.js');

    let named = function (payload) {
        console.log(payload);
    };

    let eventDispatcher = new avdw.EventDispatcher('event1', 'event2');
    eventDispatcher.subscribe('event1', function (payload) {
        console.log(payload);
    });
    eventDispatcher.subscribe('event1', named);
    eventDispatcher.subscribe('event2', named);
    eventDispatcher.fire('event1', 'payload1');
    eventDispatcher.fire('event2', 'payload2');
    eventDispatcher.unsubscribe('event2', function () {
        // do nothing
    });
    eventDispatcher.fire('event2', 'payload2');
    eventDispatcher.unsubscribe('event2', named);
    eventDispatcher.fire('event2');
})();
