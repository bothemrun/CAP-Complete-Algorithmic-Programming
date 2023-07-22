/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    //NOTE: array sort() compares with strings by default, so for numbers:
    arr.sort(function(a, b){ return fn(a) - fn(b) });
    return arr;
};
