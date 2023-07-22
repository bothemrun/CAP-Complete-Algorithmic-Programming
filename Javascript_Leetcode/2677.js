/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const ret = [];
    let i = 0;
    while(i<arr.length){
        ret.push( arr.slice(i, i+size) );
        i += size;
    }
    return ret;
};
