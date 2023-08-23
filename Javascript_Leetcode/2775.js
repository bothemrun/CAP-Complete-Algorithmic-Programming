/**
 * @param {object} obj
 * @return {object}
 */
var undefinedToNull = function(obj) {
    //base case
    //edge case
    if(obj === null) return null;
    if(typeof obj !== typeof {}) return (obj === undefined)? null:obj;

    if(Array.isArray(obj) === true){
        const arr = [];
        for(const a of obj)
            arr.push( undefinedToNull(a) );
        return arr;
    }else{
        const o = {};
        for(const key in obj)
            o[key] = undefinedToNull(obj[key]);
        return o;
    }
};

/**
 * undefinedToNull({"a": undefined, "b": 3}) // {"a": null, "b": 3}
 * undefinedToNull([undefined, undefined]) // [null, null] 
 */
