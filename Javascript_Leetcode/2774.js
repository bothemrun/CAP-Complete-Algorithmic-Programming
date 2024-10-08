/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function(target) {
    const i = this.reverse().indexOf(target);
    this.reverse();
    return (i==(-1))? (-1):( this.length-1 - i );
};


// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5
