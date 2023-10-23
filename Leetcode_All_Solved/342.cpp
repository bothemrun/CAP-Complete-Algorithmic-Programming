//O(1) without loops/recursion

//(A) first use 231. Power of Two
//from my solution of 231:
//NOTE: the rightmost 1-bit is (~x + 1) & x
//c++ uses two's compliment
//for n = -2147483648 == INT_MIN,
//n in binary: 1000....0000
// ~n: 011111...1111 == INT_MAX
//so (~n + 1) results in int overflow

//but the official solution isn't correct either,
//since "long" can be 4 or 8 bytes,
//and on this system, long has 8 bytes,
//so the correct: use "long long"

//(B) how about power of 4?
//use binary literals 0b0101...1010101

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        long long lln = n;
        //rightmost 1 bit
        long long rightmost1bit = (~lln + 1) & lln;
        //NOTE: check power of 2
        if(rightmost1bit != lln) return false;

        //NOTE: check power of 4
        int one_zero = 0b01010101010101010101010101010101;
        return ((n & one_zero) == n);
    }
};
