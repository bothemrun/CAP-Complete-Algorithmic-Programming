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
#define test 0 //1 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        #if test == 1
        cout << sizeof(int) << endl;
        cout << sizeof(long) << endl;
        #endif

        //NOTE: rightmost 1-bit works for 0, but not for n == rightmost 1-bit
        if(n == 0)return false;

        long long lln = (long long)n;
        long long rightmost_1bit = (~lln + 1) & lln;
        return lln == rightmost_1bit;
    }
};
