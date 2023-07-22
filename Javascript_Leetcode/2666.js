/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    //closure
    let called = false;
    return function(...args){
        if(called == false){
            called = true;
            //rest parameter & spread syntax
            return fn(...args);
        }else return undefined;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
