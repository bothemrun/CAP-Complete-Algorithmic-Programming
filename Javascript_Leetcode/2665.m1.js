//m1
//closure & class both serve the same purpose.
//m0 for class, m1 for closure.

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    //closure
    let cur = init;

    return {
        increment: () => {
            return ++cur;
        },
        decrement: () => {
            return --cur;
        },
        reset: () => {
            cur = init;
            return cur;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
