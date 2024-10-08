//m0
/**
 * @param {number[]} nums
 */
var ArrayWrapper = function(nums) {
    this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function() {
    //reduce(callback(accumulator, cur_val, cur_idx, arr), initial_accumulator)
    return this.nums.reduce(function(accumulator, cur_val){
        return accumulator + cur_val;
    }, 0);
}

ArrayWrapper.prototype.toString = function() {
    return JSON.stringify(this.nums);
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
