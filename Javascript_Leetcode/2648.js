/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    //[-2]: -1, [-1]: 1
    //[0]: 0, [1]: 1, [2]: 1, [3]: 2
    let last2 = (-1), last1 = 1;
    while(true){
        const ret = last1 + last2;
    
        [last1, last2] = [ret, last1];

        yield ret;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
