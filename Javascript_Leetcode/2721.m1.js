//m1
//without await, use Promise.then(), which returns an async promise.
/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    return new Promise((resolve, reject) => {
        if(functions.length === 0) resolve([]);

        const arr = Array(functions.length);
        let settled = 0;

        for(let i=0;i<functions.length;i++){
            //NOTE: Promise.then() returns an async promise immediately,
            //NOTE: so it won't wait.
            //NOTE: so the functions run in parallel.
            functions[i]().then((value) => {
                arr[i] = value;
                settled++;
                if(settled === functions.length) resolve(arr);
            }).catch((err) => {
                reject(err);
            });
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
