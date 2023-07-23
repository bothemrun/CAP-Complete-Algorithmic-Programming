//for arrays / objects, the order of values/keys does / doesn't matter.
//reasonable. since for arrays, the keys are the indices.
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    //(1) primitive type values
    if(typeof o1 !== typeof {} && typeof o2 !== typeof {}) return o1 === o2;

    //(2) types
    if(typeof o1 !== typeof o2) return false;
    if(Array.isArray(o1) !== Array.isArray(o2)) return false;

    //NOTE: now both are object types
    //(3) typeof null is object
    //NOTE: same objects with different key order are missed out.
    if(o1 === o2) return true;
    //NOTE: Object.keys() can't take null, although typeof null is object
    if(o1 === null || o2 === null) return o1 === o2;

    //(4) check all keys & values
    if(Object.keys(o1).length !== Object.keys(o2).length) return false;
    for(const key in o1){
        if(!(key in o2)) return false;

        if(areDeeplyEqual(o1[key], o2[key]) === false) return false;
    }

    return true;
};
