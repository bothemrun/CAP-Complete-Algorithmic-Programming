//m1
//reduce() & reverse() for function composition.
//reduce can also be applied on function arrays.
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        functions.reverse();

        return functions.reduce(
            function(accumulator, cur_val_func){
                return cur_val_func(accumulator);
            },
            x
        );
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
