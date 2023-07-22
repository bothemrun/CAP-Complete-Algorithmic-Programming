//m0
/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        //rest parameter

        return new Promise(async function(resolve, reject){
            const setTimeout_id = setTimeout(() => {
                reject("Time Limit Exceeded")
            }, t);

            //spread syntax. closure
            const ret = await fn(...args).catch(reject);

            clearTimeout(setTimeout_id);
            resolve(ret);
        });
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
