/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */

function type3(obj){
    if(typeof obj !== typeof {}) return 0;
    if(Array.isArray(obj) === true) return 1;
    return 2;
}

const null_diff = {};
function empty_obj(obj){
    if(type3(obj) !== 2) return false;
    return Object.entries(obj).length === 0;
}

function objDiff(obj1, obj2) {
    //base case
    if(type3(obj1) !== type3(obj2) ) return [obj1, obj2];

    if(type3(obj1) === 0) return (obj1 === obj2)? null_diff:[obj1, obj2];

    const obj = {};
    //key in obj2 also works for arrays
    for(const key in obj1)if(key in obj2){
        const diff = objDiff( obj1[key], obj2[key] );

        if(empty_obj(diff) === false) obj[key] = diff;
    }

    return obj;
};
