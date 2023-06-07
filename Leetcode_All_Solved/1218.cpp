//m0
//include<algorithm>
#define arr_bound ((int)1e4)
#define offset arr_bound
#define memo_size (3 * offset + 4) //NOTE: trap: not 2*offset

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n =arr.size();

        int max_ari = 0;
        int prefix_longest[memo_size] = {0};

        for(int i=0;i<n;i++){
            int cur_ari = 1;

            int pre_idx = arr[i] - difference;
            if(pre_idx >= (-arr_bound)){
                int pre_ari = prefix_longest[ offset + pre_idx ];

                cur_ari = max(cur_ari, 1 + pre_ari);
                max_ari = max(max_ari, cur_ari);
            }

            //NOTE: update. ok with cur_ari==1
            prefix_longest[ offset + arr[i] ] = cur_ari;
        }

        return max_ari;
    }
};
