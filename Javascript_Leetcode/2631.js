/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const obj = {};
    for(const item of this){
        const s = fn(item);
        if(s in obj) obj[s].push(item);
        else obj[s] = [item];
    }
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
