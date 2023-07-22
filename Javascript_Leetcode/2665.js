//m0
//closure & class both serve the same purpose.
//m0 for class, m1 for closure.

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

class Counter{
    constructor(init){
        this.init = init;
        this.cur = init;
    }

    increment(){
        return ++this.cur;
    }

    decrement(){
        return --this.cur;
    }

    reset(){
        this.cur = this.init;
        return this.cur;
    }
};

var createCounter = function(init) {
    return new Counter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
