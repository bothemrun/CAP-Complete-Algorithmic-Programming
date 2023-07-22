//m1
//without await fn
/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        return new Promise(function(resolve, reject){
            const setTimeout_id = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            //spread syntax. closure
            fn(...args)
            .then((ret) => {
                resolve(ret);
            })
            .catch((err) => {
                reject(err);
            });
        });
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
