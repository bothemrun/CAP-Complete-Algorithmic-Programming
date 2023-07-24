//m0
//use Array.flat()
/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    const flatten = arr.flat(Infinity);
    for(let i=0;i<flatten.length;i++){
        yield flatten[i];
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
