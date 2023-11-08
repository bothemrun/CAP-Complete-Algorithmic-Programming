//[A] fastest way
//1. draw a picture.
//2. the fastest way consists of a diagonal and a vertical/horizontal line.
//3. fastest = max(abs(sx-fx), abs(sy-fy))

//[B] remain steps
//1. then just go back and forth.
//2. the all remain steps == 1 or 0.
//3. if remain steps == even, good.

//[C] remain steps == odd:
//1. if a diagonal exists in [A], replace it with 1 vertical/horizontal each.
//2. if a vertical/horizontal exists, replace it with 1 diagonal + 1 horizontal/vertical.
//3. other even steps can use [B].

//[D] edge case for [C]
//1. if neither exists, that means [A] fastest == 0.
//2. for remain steps >= 3, we can use 1 diagoanl + 1 vertical + 1 horizontal for that odd parity.
//3. but if remain steps == 1, then [D].2 fails.

#include<stdlib.h>
#include<algorithm>

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff1 = abs(sx - fx);
        int diff2 = abs(sy - fy);
        int fastest = max(diff1, diff2);

        if(t < fastest) return false;

        int remain = t - fastest;
        if(remain%2 == 0) return true;

        //now remain steps == odd
        if(fastest != 0) return true;

        //now fastest == 0, remain steps == odd
        if(t == 1) return false;
        else return true;
    }
};
