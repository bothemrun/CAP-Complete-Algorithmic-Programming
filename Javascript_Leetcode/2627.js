/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeout_id = undefined;

    return function(...args) {
        //closure. rest parameter. spread syntax.
        if(timeout_id !== undefined)
            clearTimeout(timeout_id);
        timeout_id = setTimeout(() => {
            timeout_id = undefined;
            
            fn(...args);
        }, t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
