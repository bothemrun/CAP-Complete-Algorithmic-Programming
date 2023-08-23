/**
 * @param {any} obj1
 * @param {any} obj2
 * @return {any}
 */

function type4(o){
    //edge case
    if(o === null) return 3;
    if(Array.isArray(o)) return 0;
    if(typeof o === typeof {}) return 1;
    return 2;
}

var deepMerge = function(obj1, obj2) {
    const t1 = type4(obj1);
    const t2 = type4(obj2);
    //base case
    if(t1 !== t2 || t1 >= 2 || t2 >= 2) return obj2;

    const oa = (t1 === 0)? []:{};

    for(const key in obj1)if(key in obj2)
        oa[key] = deepMerge(obj1[key], obj2[key]);
    for(const key in obj1)if(!(key in obj2))
        oa[key] = obj1[key];
    for(const key in obj2)if(!(key in obj1))
        oa[key] = obj2[key];
    return oa;
};

/**
 * let obj1 = {"a": 1, "c": 3}, obj2 = {"a": 2, "b": 2};
 * deepMerge(obj1, obj2); // {"a": 2, "c": 3, "b": 2}
 */

