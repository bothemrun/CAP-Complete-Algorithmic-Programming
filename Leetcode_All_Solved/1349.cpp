//m0
//recursion with memo. bitmask dp. O(m * 2^n * 2^n * n) = O(8^2 * 4^8) = 4e6
//NOTE: popcount vector + valid seat masks.

//NOTE: we could use __builtin_popcount() or C++20 popcount().
//NOTE: but we preprocess a popcount vector.

//NOTE: pitfall: operator precedence:
//NOTE: more prioritized: 
//arithmetic(+-*/) > 
//bitwise shift > 
//relational(== != >) > 
//bitwise ops (& | ^) >
//logical ops (&& ||)

#define notyet (-1)
#define none (-2)

#define subset(small, big) ( (small & big) == small )
#define neighbor(m) (m & (m<<1))
#define diagonal(a, b) ( (a & (b<<1)) || ((a<<1) & b) )

#include<algorithm>
#include<assert.h>

class Solution {
public:
    int m, n;
    vector<vector<int>> memo;

    vector<int> valid;
    vector<int> popcount;

    inline bool check_row(const int& i, const int& mask){
        return subset(mask, valid[i]) && neighbor(mask)==false;
    }

    inline bool check_cross(const int& m1, const int& m2){
        return diagonal(m1, m2)==false;
    }

    int enum_mask(const int& i, const int& mask){
        assert(i>=0);
        if(memo[i][mask] != notyet) return memo[i][mask];

        if(!check_row(i, mask)) return memo[i][mask] = none;
        if(i==0) return memo[i][mask] = popcount[mask];


        int ret = none;
        for(int pre_mask=0;pre_mask < (1<<n);pre_mask++)if(
            enum_mask(i-1, pre_mask) != none &&
            check_cross(mask, pre_mask)
        ){
            ret = max(
                ret,
                popcount[mask] + enum_mask(i-1, pre_mask)
            );
        }

        return memo[i][mask] = ret;
    }

    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size();
        n = seats.back().size();

        //valid bits
        valid.resize(m);
        for(int i=0;i<m;i++){
            int v = 0;
            for(int j=0;j<n;j++)
                v = (v<<1) + (seats[i][j] == '.');

            valid[i] = v;
            printf("v: %d\n", v);
        }

        //popcount
        popcount.resize(1<<n);
        popcount[0] = 0;
        for(int mask=1;mask < (1<<n);mask++)
            popcount[mask] = popcount[mask>>1] + (mask & 1);
        

        memo.resize(m, vector<int>(1<<n, notyet));
        int ans = none;
        for(int mask=0;mask < (1<<n);mask++)
            ans = max(
                ans,
                enum_mask(m-1, mask)
            );

        return ans;
    }
};
