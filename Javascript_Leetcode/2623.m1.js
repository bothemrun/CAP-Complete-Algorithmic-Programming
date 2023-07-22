//m1
//JSON.stringify() + object
/**
 * @param {Function} fn
 */
function memoize(fn) {
    //closure
    memo = {};

    return function(...args) {
        //rest parameter is an array
        const key = JSON.stringify(args);
        if(key in memo) return memo[key];
        else return memo[key] = fn(...args);
        //spread syntax
        //wrong: else return memo[key] = fn(args);
        //since fn parameter isn't an array.
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
