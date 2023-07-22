//m1
//recursion
/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    const res = [];

    function flatten(sub, depth){
        for(const item of sub){
            if(depth > 0 && (typeof item) === (typeof []) ){
                flatten(item, depth - 1);
            }else{
                res.push(item);
            }
        }
    }

    flatten(arr, n);
    return res;
};
