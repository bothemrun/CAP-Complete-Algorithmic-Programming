//m0
//use Promise.all()
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    const resolve_val = await Promise.all([promise1, promise2]);

    let ret = 0;
    for(const res of resolve_val)
        ret += res;
    return ret;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
