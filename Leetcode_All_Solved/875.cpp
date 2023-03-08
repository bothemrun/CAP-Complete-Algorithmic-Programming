#define ceil(a,b) ( a/b + ( (a%b==0)? 0:1) )
#include<assert.h>
#include<limits.h>
#include<algorithm>
class Solution {
public:
    inline int need_time(const vector<int>& piles, int k){
        if(k == 0)return INT_MAX;
        assert(k != 0);
        
        int cnt = 0;
        for(const int& p: piles)
            cnt += ceil(p, k);
        return cnt;
    }

    int binary(const vector<int>& piles, const int& low, const int& high, const int& h){
        int mid = (high-low)/2 + low;
        int time_mid;
        if(
            h < need_time(piles, mid-1) &&
            (time_mid = need_time(piles, mid) ) <= h
        ) return mid;

        if( time_mid > h )
            return binary(piles, mid+1, high, h);
        else return binary(piles, low, mid, h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        return binary(piles, 1, *max_element(piles.begin(), piles.end()), h);
    }
};
