/**
 * @return {number}
 */
var argumentsLength = function(...args) {
    //rest parameter is an array.
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
