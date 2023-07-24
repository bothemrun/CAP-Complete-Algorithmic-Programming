//m1
//without Array.flat(Infinity)
//use yield* generator_iterator
/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* recur(arr) {
    //base case: int
    if(Array.isArray(arr) === false){
        yield arr;
        return;
    }

    for(const a of arr)
        yield* recur(a);
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
