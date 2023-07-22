//m0
//use await
/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    return new Promise((resolve, reject) => {
        if(functions.length == 0) resolve([]);

        //NOTE: not new Array(length) !!
        const arr = Array(functions.length);
        let settled = 0;

        for(let i=0;i<functions.length;i++){
            //for loop is synchronous, won't wait for async / promises.
            //so these functions are run in parallel.
            (async function(){
                const ret = await functions[i]()
                .catch((err) => {
                    reject(err);
                });

                arr[i] = ret;
                settled++;
                if(settled === functions.length) resolve(arr);
            })();
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
