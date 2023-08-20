/**
 * @param {Array<Function>} functions
 * @param {number} ms
 * @return {Array<Function>}
 */

//if use: delayAll = async function(...) --> RE
var delayAll = function(functions, ms) {
    async function await_setTimeout(time){
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                resolve();
            }, time);
        });
    }

    let delay_functions = [];
    for(const func of functions){
        delay_functions.push(
            async function(){
                await await_setTimeout(ms);

                try{
                    const res = await func();
                    return Promise.resolve(res);
                }catch(err){
                    return Promise.reject(err);
                }
            }
        );
    }

    return delay_functions;
};


