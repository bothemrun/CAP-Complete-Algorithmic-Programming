//m1
//O(nkm) from method 0 O(nkmm) with prefix sum of dp memo.  recursion with memo.
#define mod ((long long)1e9 + 7)
#define PLL pair<long long, long long>
#define notyet PLL(INT_MIN, INT_MIN)
#include<limits.h>
#include<utility>
#include<assert.h>

class Solution {
public:
    vector<vector<vector<PLL>>> memo2prefix;
    //NOTE: prefix[i][cost][prefix_max] := 
    //sum of memo[i][cost][ 1 ~ prefix_max-1 ]

    PLL enum_prefix_max(const int& i, const int& cost, const long long& prefix_max){

        if(cost==0) return PLL(0, 0);
        if(prefix_max==0) return PLL(0, 0);
        assert(cost>=1 && prefix_max>=1);

        if(i==0)
            return (cost==1)? PLL(1, prefix_max):PLL(0, 0);
            //return (cost==1)? PLL(1, 1):PLL(0, 0);
        assert(i>=1);


        if(memo2prefix[i][cost][prefix_max] != notyet)
            return memo2prefix[i][cost][prefix_max];

        //(1) the prefix max is not updated
        //so just choose arr[i] from 0~prefix_max
        long long way = (
            prefix_max *
            enum_prefix_max(i-1, cost, prefix_max).first
        )%mod;

        //(2) the prefix max is updated
        //NOTE: O(nkmm) method uses a for loop to sum over DP for 0 ~ prefix_max-1
        //NOTE: here use a prefix sum of dp memo
        way = (
            way +
            enum_prefix_max(i-1, cost-1, prefix_max-1).second
        )%mod;

        long long prefix_sum = (way + enum_prefix_max(i, cost, prefix_max-1).second )%mod;

        return memo2prefix[i][cost][prefix_max] = PLL(way, prefix_sum);
    }

    int numOfArrays(int n, int m, int k) {
        memo2prefix.resize(n, vector<vector<PLL>>(k+1, vector<PLL>(m+1, notyet) ) );

        return enum_prefix_max(n-1, k, m).second;
    }
};
