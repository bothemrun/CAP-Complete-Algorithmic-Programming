//[A] no patterns, so brute force enumeration.
//1. brute force enumeration includes backtracking & bitmask dp.

//[B] backtracking ??
//1. O(n!) = O(15!) = 1e12, TLE

//[C] bitmask dp
//1. O(n * 2^n * n) = O(2^15 * 15^2) = 7e6

#define notyet (-1)

class Solution {
public:
    int n;

    vector<vector<int>> memo;
    int enum_num(const int& i, const int& mask){
        if(i==n+1){
            return 1;
        }

        if(memo[i][mask] != notyet)
            return memo[i][mask];
        
        int ret = 0;
        for(int num=1, submask=1;num<=n;num++, submask <<= 1){
            if( (mask & submask) != 0) continue;
            if( !( i%num==0 || num%i==0 ) ) continue;

            ret += enum_num(i+1, mask | submask);
        }

        return memo[i][mask] = ret;
    }

    int countArrangement(int n) {
        this->n = n;
        memo.resize(n + 1, vector<int>(1<<n, notyet));

        return enum_num(1, 0);
    }
};
