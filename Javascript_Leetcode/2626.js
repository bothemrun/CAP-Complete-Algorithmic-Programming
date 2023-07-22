//m0
//builtin Array.reduce( callback(accumulator, cur_value, cur_index, arr), initialValue )
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    return nums.reduce(fn, init);
};
