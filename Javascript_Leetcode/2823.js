/**
 * @param {Object} obj
 * @param {Function} fn
 * @return {Object|undefined}
 */
var deepFilter = function(obj, fn) {
    //base case
    if(obj === null || typeof obj !== typeof {})
        return (fn(obj) === true)? obj:undefined;
    
    if(Array.isArray(obj) === true){
        const arr = [];
        for(const a of obj){
            const fil = deepFilter(a, fn);

            if(fil !== undefined) arr.push(fil);
        }

        return (arr.length === 0)? undefined:arr;
    }else{
        const o = {};
        for(const key in obj){
            const fil = deepFilter(obj[key], fn);

            if(fil !== undefined) o[key] = fil;
        }

        return ( Object.entries(o).length === 0 )? undefined:o;
    }
};
