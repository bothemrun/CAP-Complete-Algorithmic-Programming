//m1

//instead of:
//builtin Array.reduce( callback(accumulator, cur_value, cur_index, arr), initialValue )
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let accumulator = init;
    for(const cur_val of nums)
        accumulator = fn(accumulator, cur_val);
    return accumulator;
};
