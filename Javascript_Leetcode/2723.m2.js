//m2
//use Promise.then()
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let ret = 0;
    try{
        return promise1.then((val1) => {
            return promise2.then((val2) => {
                return val1+val2;
            });
        })
    }catch(err){
        console.error(err);
        throw error;
    }
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
