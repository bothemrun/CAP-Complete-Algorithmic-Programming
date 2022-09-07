//m1
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<assert.h>
class Solution {
public:
    inline bool good(int i){
        if(i == 0)return true;
        return !isBadVersion(i);
    }
    int binary(int low, int high){
        int mid = low + (high-low)/2;
        int good_mid = good(mid);
        int good_mid_left = good(mid-1);//NOTE: can be 0
        if( good_mid_left && !good_mid )return mid;//also for size 1
        if(low == high) assert(0);
        
        if(good_mid)return binary(mid+1, high);
        else return binary(low, mid);
    }
    int firstBadVersion(int n) {
        return binary(1, n);
    }
};
