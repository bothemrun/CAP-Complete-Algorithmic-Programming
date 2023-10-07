//m0
//O(nmkm) recursion with memo

#define mod ((long long)1e9 + 7)
#define notyet (-1)
#include<assert.h>

class Solution {
public:
    vector<vector<vector<long long>>> memo;

    long long enum_prefix_max(const int& i, const int& cost, const long long prefix_max){
        if(cost == 0) return 0;
        if(i==0) return (cost==1)? 1:0;
        assert(i>=0 && cost>=1 && prefix_max>=1);

        if(memo[i][cost][prefix_max] != notyet) return memo[i][cost][prefix_max];


        //(case 1) the prefix max is not updated.
        //then just choose arr[i] from 1 ~ prefix_max
        long long way = (prefix_max * enum_prefix_max(i-1, cost, prefix_max) )%mod;


        //(case 2) the prefix max is updated
        for(int last_prefix_max=1; last_prefix_max < prefix_max; last_prefix_max++){
            way += enum_prefix_max(i-1, cost-1, last_prefix_max);
            way %= mod;
        }

        return memo[i][cost][prefix_max] = way;
    }

    int numOfArrays(int n, int m, int k) {
        memo.resize(n, vector<vector<long long>>(k+1, vector<long long>(m+1, notyet) ) );

        long long ans = 0;
        for(long long prefix_max=1;prefix_max<=m;prefix_max++)
            ans = (ans + enum_prefix_max(n-1, k, prefix_max) )%mod;
        
        return ans;
    }
};
