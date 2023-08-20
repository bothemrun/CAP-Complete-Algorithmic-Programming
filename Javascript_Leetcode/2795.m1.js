//m1
//self-made Promise.allSettled(), 
//use forEach with await for nonblocking, instead of for loop with await blocking
/**
 * @param {Array<Function>} functions
 * @return {Promise}
 */
var promiseAllSettled = function(functions) {
    return new Promise((resolve, rejct) => {
        //edge case. length 0 not go to finally block
        if(functions.length === 0) resolve([]);

        let settle_cnt = 0;
        const settle = Array(functions.length);

        //NOTE: for loop with await will be blocking !!!!
        functions.forEach( async function(f, i){
            try{
                const result = await f();

                settle[i] = {
                    status: "fulfilled",
                    value: result,
                };
            }catch(err){
                settle[i] = {
                    status: "rejected",
                    reason: err,
                };
            }finally{
                if(++settle_cnt === functions.length) resolve(settle);
            }
        } );
    });
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
