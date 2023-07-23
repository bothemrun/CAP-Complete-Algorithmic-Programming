//m0
//callbacks in arrays

class EventEmitter {
    constructor(){
        this.event2callback = {};
    }

    subscribe(event, cb) {
        if(event in this.event2callback) this.event2callback[event].push(cb);
        else this.event2callback[event] = [cb];
        
        return {
            unsubscribe: () => {
                this.event2callback[event] = this.event2callback[event].filter(function(callback){
                    return callback !== cb;
                });

                return undefined;
            }
        };
    }

    emit(event, args = []) {
        if(!(event in this.event2callback)) return [];

        return this.event2callback[event].map(function(callback){
            //spread syntax
            return callback(...args);
        });
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
