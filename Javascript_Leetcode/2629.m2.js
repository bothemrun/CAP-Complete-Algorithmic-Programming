//m2
//reduceRight() for function composition. (without reverse() )
//reduce can also be applied on function arrays.

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        return functions.reduceRight(
            function(accumulator, cur_val_funct){
                return cur_val_funct(accumulator);
            },
            x
        );
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
