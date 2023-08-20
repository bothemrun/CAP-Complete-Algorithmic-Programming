//m0
//use Promise.allSettled()
/**
 * @param {Array<Function>} functions
 * @return {Promise}
 */
var promiseAllSettled = function(functions) {
    //nonblocking map()
    const ps = functions.map(function(f){
        return f();
    });
    return Promise.allSettled(ps);
};


/**
 * const functions = [
 *    () => new Promise(resolve => setTimeout(() => resolve(15), 100))
 * ]
 * const time = performance.now()
 *
 * const promise = promiseAllSettled(functions);
 *              
 * promise.then(res => {
 *     const out = {t: Math.floor(performance.now() - time), values: res}
 *     console.log(out) // {"t":100,"values":[{"status":"fulfilled","value":15}]}
 * })
 */
