//TODO: not understand all.

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Promise<any>}
 */
var promisePool = async function(functions, n) {
    let next_idx = Math.min(n, functions.length);
    function call_next(){
        if(next_idx === functions.length) return;

        //functions[next_idx++]().then(call_next);
        return functions[next_idx++]().then(call_next);
    }

    const pool = functions.slice(0, next_idx).map(async function(f){
        return f().then(call_next);
    });
    return Promise.all( pool );
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
