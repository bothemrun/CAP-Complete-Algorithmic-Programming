//m3
//O(k*n)

//1. use a jump table to jump back to last index of the same value.

//2. dp_end[i][diff] := end at i (must choose [i]), at most "diff" different pairs avaible (not exactly)

//2.a. dp_choose_or_skip[i][diff] --> no. if the last recursion uses same pair (no diff-1), then can't skip it !!!

//3. so still need dp prefix max

#define max_n ((int)5e3 + 1)
#define max_k (50+1)
#define no_jump (-1)
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> val2last_idx;
        int jump[max_n];
        for(int i=0;i<n;i++){
            jump[i] = (
                (val2last_idx.count( nums[i] )==0)?
                no_jump:
                val2last_idx[ nums[i] ]
            );
            
            //update
            val2last_idx[ nums[i] ] = i;
        }


        int dp_end[max_n][max_k];//no need to init
        int prefix_max[max_k] = {0};

        for(int i=0;i<n;i++){
            //must diff=k~0, not 0~k,
            //which ensures we use last [i]'s memo,
            //since we use memo[diff-1]
            for(int diff=k;diff>=0;diff--){
                
                //1 big max() is more clear than many updates / max().
                dp_end[i][diff] = max({
                    1, //self
                    (
                        (jump[i] == no_jump)?
                        1:
                        (1 + dp_end[ jump[i] ][diff])
                    ), //same value pair
                    (
                        (diff-1>=0)?
                        (1 + prefix_max[diff-1]):
                        1
                    ) //possibly different or same pair
                });

                //update prefix max for dp_end for previous i
                prefix_max[diff] = max(
                    prefix_max[diff],
                    dp_end[i][diff]
                );
            }
        }
        return prefix_max[k];
    }
};
