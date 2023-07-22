//m0
//string + object
/**
 * @param {Function} fn
 */
function memoize(fn) {
    //closure
    memo = {};
    
    delim = "$";
    function stringify(...args){
        let key = "";
        for(const arg of args)
            key += arg + delim;
        return key;
    }

    return function(...args) {
        //rest parameter & spread syntax
        const key = stringify(...args);
        if(key in memo) return memo[key];
        return memo[key] = fn(...args);
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
