//m0
/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        //NOTE: function.length. spread syntax. rest parameter
        if(args.length === fn.length) return fn(...args);

        return function(...remain_args){
            //spread
            return curried(...args, ...remain_args);
        };
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
