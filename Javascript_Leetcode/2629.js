//m0
//use iterations
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let accumulator = x;
        for(let i=functions.length-1;i>=0;i--)
            accumulator = functions[i](accumulator);
        return accumulator;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
