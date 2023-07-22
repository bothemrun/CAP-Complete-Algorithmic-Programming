//m1
//instead of Array.filter(function(cur_value, cur_index, arr))

//use Boolean(fn(...)) instead of fn(...) === true

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const ret = [];
    for(let i=0;i<arr.length;i++){
        //if(fn(arr[i], i) === true)
        if(Boolean( fn(arr[i], i) ) === true)
            ret.push(arr[i]);
    }

    return ret;
};
