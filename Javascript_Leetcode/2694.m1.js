//m1
//callbacks in sets
class EventEmitter {
    constructor(){
        this.event2callback = {};
    }
    
    subscribe(event, cb) {
        if(event in this.event2callback) this.event2callback[event].add(cb);
        else this.event2callback[event] = new Set([cb]);
        
        return {
            unsubscribe: () => {
                this.event2callback[event].delete(cb);

                if(this.event2callback[event].size === 0){
                    //delete property from object
                    delete this.event2callback[event];
                }

                return undefined;
            }
        };
    }

    emit(event, args = []) {
        if(!(event in this.event2callback)) return [];

        const res = [];
        for(const callback of this.event2callback[event])
            res.push( callback(...args) );//spread syntax
        return res;
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
