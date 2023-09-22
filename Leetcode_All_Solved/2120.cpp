//O(m) by prefix hash and prefix sum

// Thinking Process:

// (0) first think about its 1D problem.

// (1) for any i, find smallest j (j >= i),
// (1.1) s.t. the displacement between [i, j] causes startPos going out of bounds

// (2) how to preprocess the displacement between [i, j]?
// (2.1) range sum by prefix (or suffix) sum.

// (3) then use a hash map to check if there exists j s.t. the displacement [i, j] causes out of bounds.

// (4) use a suffix hash to ensure j >= i

// (5) iterate backwards and replace the suffix hash if the key already exists.
// (5.1) --> ensures the smallest j.

// (6) all suffix things simplified by treating them backwards.

//ref: razimantv
// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/solutions/2458199/o-m-solution-using-prefix-sum-and-hashmap/

#include<unordered_map>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        const int m = s.size();

        unordered_map<char, int> dir_x = {
            {'U', -1},
            {'D', 1}
        };
        unordered_map<char, int> dir_y = {
            {'L', -1},
            {'R', 1}
        };

        vector<int> prefix_x(m);
        vector<int> prefix_y(m);
        //if not found, then inserts (key, 0) to the map.
        prefix_x.front() = dir_x[ s.front() ];
        prefix_y.front() = dir_y[ s.front() ];

        for(int i=1;i<m;i++){
            prefix_x[i] = prefix_x[i-1] + dir_x[ s[i] ];
            prefix_y[i] = prefix_y[i-1] + dir_y[ s[i] ];
        }


        vector<int> ans(m);
        for(int i=0;i<m;i++) ans[i] = m - i;

        unordered_map<int, int> suffix_hash_x;
        unordered_map<int, int> suffix_hash_y;
        for(int i=m-1;i>=0;i--){

            suffix_hash_x[ prefix_x[i] ] = i;
            suffix_hash_y[ prefix_y[i] ] = i;


            //range-based loop
            for(int bound: {-1, n} ){
                int minus_prefix_x = (i-1 >= 0)? prefix_x[i-1]:0;
                int minus_prefix_y = (i-1 >= 0)? prefix_y[i-1]:0;

                //want j s.t. start + range_sum[i, j] == bound
                //or: start + prefix[j] - prefix[i-1] == bound
                //or: prefix[j] == bound - start + prefix[i-1]

                int prefix_x_j = bound - startPos[0] + minus_prefix_x;
                int prefix_y_j = bound - startPos[1] + minus_prefix_y;

                if( suffix_hash_x.count(prefix_x_j) != 0)
                    ans[i] = min(
                        ans[i],
                        suffix_hash_x[prefix_x_j] - 1 - (i-1)
                    );
                
                if( suffix_hash_y.count(prefix_y_j) != 0)
                    ans[i] = min(
                        ans[i],
                        suffix_hash_y[prefix_y_j] - 1 - (i-1)
                    );
            }
        }

        return ans;
    }
};
