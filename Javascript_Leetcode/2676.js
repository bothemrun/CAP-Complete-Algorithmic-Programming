/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    let lock = false;
    let wait_args = null;

    function lock_setTimeout(){
        lock = true;
        wait_args = null;

        setTimeout(function(){
            lock = false;

            if(wait_args !== null){
                const args = wait_args;
                wait_args = null;

                throttle_fn(...args);
            }
        }, t);
    }

    function throttle_fn(...args) {
        if(lock === true){
            wait_args = args;//replace
        }else{
            fn(...args);
            lock_setTimeout();
        }
    }

    return throttle_fn;
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
