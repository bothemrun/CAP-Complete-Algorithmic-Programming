//m1
//rest parameter for-of
/**
 * @return {number}
 */
var argumentsLength = function(...args) {
    //rest parameter is an array.
    let cnt = 0;
    for(const arg of args) cnt++;
    return cnt;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
