//m1
//instead of Array.map()

//Why not use for-in for array iterations.

//initialize size with Array(length)
//not new Array(length)
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    //not: new Array(arr.length)
    const ret = Array(arr.length);

    //not: for(const i of arr)
    for(let i=0;i<arr.length;i++)
        ret[i] = fn(arr[i], i);
    return ret;
};
