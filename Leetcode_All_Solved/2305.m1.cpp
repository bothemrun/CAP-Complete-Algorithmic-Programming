//m1

//NOTE: m1 enumerate submask from 0, so the termination case for child == 0 is:
//NOTE: must use all bitmask.


//NOTE: pitfall: bitwise & and != / == operator precedence.
//NOTE: pitfall: bitwise not is ~ flipped, not logical !.


//bitmask dp. recursion with memo.

//NOTE: submask enumeration of a bitmask:
//NTOE: https://cp-algorithms.com/algebra/all-submasks.html#enumerating-all-submasks-of-a-given-mask
//in O(3^k), or O(4^k) without the submask enumeration technique.

//O(n * 4^k) = O(8 * 4^8) = 5e5, greatly imroved from backtracking O(k^n).

#define notyet INT_MAX
#include<limits.h>
#include<algorithm>

class Solution {
public:
    vector<int> bitmask_sum;

    vector<vector<int>> memo;
    int enum_child_mask(const int& child, const int& prefix_mask){
        //NOTE: base case is not child < 0
        if(child == 0) return bitmask_sum[prefix_mask];

        if(memo[child][prefix_mask] != notyet) return memo[child][prefix_mask];

        int minmax = INT_MAX;
        for(int submask=0;submask<=prefix_mask;submask++)if( ( submask & ~prefix_mask ) == 0){
            minmax = min(
                minmax,
                max(
                    bitmask_sum[submask],
                    enum_child_mask(
                        child-1,
                        prefix_mask ^ submask
                    )
                )
            );
        }

        return memo[child][prefix_mask] = minmax;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();

        //NOTE: enumerate bitmask sum in O(2^n * n)
        bitmask_sum.resize(1<<n, 0);
        for(int mask=0;mask<(1<<n);mask++)
            for(int b=0;b<n;b++)if( ( mask & (1<<b) ) != 0)
                bitmask_sum[mask] += cookies[b];


        memo.resize(k, vector<int>(1<<n, notyet));
        return enum_child_mask(k-1, (1<<n) - 1);
    }
};
