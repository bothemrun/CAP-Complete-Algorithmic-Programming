#include<assert.h>
#include<unordered_map>
class Solution {
public:
    int test_cnt = 0;
    int n;
    vector<bool> idx_done;
    
    vector<unordered_map<int, int>> val2cnt;
    //NOTE: suffix sum value combinations to counts
    //NOTE: built from back to front
    //NOTE: use [(i+1)%2], and store in [i%2]

    void dfs_suffix(const vector<int>& nums, const int& i){
        if(idx_done[i] == true)return;
        if(i == n){
            //only once
            assert( (++test_cnt) <= 1 );

            val2cnt[ n%2 ][0] = 1;//NOTE
            idx_done[i] = true;
            return;
        }

        assert(i < n);

        //NOTE: call recursive before clear() !!!
        if(idx_done[i+1] == false) dfs_suffix(nums, i+1);

        //NOTE: use [(i+1)%2], and store in [i%2]
        val2cnt[ i%2 ].clear();


        for(int sign=(-1);sign<=1;sign+=2){
            //NOTE: if(idx_done[i+1] == false) dfs_suffix(nums, i+1);

            for(unordered_map<int,int>::iterator it = val2cnt[(i+1)%2].begin(); it != val2cnt[(i+1)%2].end();it++){
                int new_val = sign * nums[i] + it->first;
                if(val2cnt[i%2].count(new_val) == 0)
                    val2cnt[i%2][new_val] = it->second;
                else val2cnt[i%2][new_val] += it->second;
                //NOTE: so i==n, [0] init as 1
            }
        }

        idx_done[i] = true;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        val2cnt = vector<unordered_map<int,int>>(2, unordered_map<int,int>() );

        idx_done = vector<bool>(n + 1, false);
        
        dfs_suffix(nums, 0);

        if(val2cnt[0%2].count(target) == 0)return 0;
        return val2cnt[0%2][target];
    }
};


