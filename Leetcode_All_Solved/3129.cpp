//m0
//knapsack dp

//O(zero * one * limit) = O(200^3 * 2) = 1.6e7
//the time complexity is large, so we have to use arrays instead of vectors for the memo

//ugly code, method, and logic.
#define max_size 200

class Solution {
public:
    const int mod = (int)1e9 + 7;
    const int notyet = (-1);
    int memo[max_size+1][max_size+1][max_size+1][2];

    int zero, one, limit;
    //for the beginning, set last = 0 for accessing the memo.
    //and later represent it as (-1) by last1
    int knapsack_suf_conse(int z, int o, int conse, int last=0){
        if(conse > limit) return 0;

        if(z==zero){
            //'cuz in the last recursion, we either choose 0 or 1
            assert(one - o > 0);
            return (one - o <= limit)? 1:0;
        }
        if(o==one){
            assert(zero - z > 0);
            return (zero - z <= limit)? 1:0;
        }

        if(memo[z][o][conse][last] != notyet) return memo[z][o][conse][last];

        int last1 = (conse==0)? (-1):last;

        return memo[z][o][conse][last] = (
            knapsack_suf_conse(z+1, o, (last1 == 0)? (conse+1):1, 0) +
            knapsack_suf_conse(z, o+1, (last1 == 1)? (conse+1):1, 1)
        )%mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        this->zero = zero;
        this->one = one;
        this->limit = limit;

        for(int z=0;z<=zero;z++)
            for(int o=0;o<=one;o++)
                for(int conse=0;conse<=limit;conse++)
                    for(int last=0;last<=1;last++)
                        memo[z][o][conse][last] = notyet;

        return knapsack_suf_conse(0, 0, 0);
    }
};
