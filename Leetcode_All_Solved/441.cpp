#include<assert.h>
class Solution {
public:
    inline long long series(long long r){
        return ( r*(r+1) )/2;
    }
    int binary(const long long& n, long long low, long long high){
        long long mid = low + (high-low)/2;
        long long series_mid = series(mid);
        long long series_mid1 = series(mid+1);
        if(series_mid <= n && n < series_mid1)return mid;
        if(low == high)assert(0);
        
        if(series_mid > n)return binary(n, low, mid);
        else return binary(n, mid+1, high);
    }
    int arrangeCoins(int n) {
        return binary(n, 1, n);
    }
};
