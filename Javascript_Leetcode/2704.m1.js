//m1
//m0 uses closure, m1 uses class

/**
 * @param {string} val
 * @return {Object}
 */

class Expect{
    constructor(val){
        this.val = val;
    }

    toBe(val2){
        if(this.val === val2) return true;
        else throw "Not Equal";
    }

    notToBe(val2){
        if(this.val !== val2) return true;
        else throw "Equal";
    }
};

var expect = function(val) {
    return new Expect(val);
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
