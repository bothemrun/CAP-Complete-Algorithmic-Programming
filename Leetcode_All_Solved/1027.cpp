//m0
//bottom up dp. longest increasing subsequence O(n^2) time & O(n^2) space.
//for memo[i], it has a hash map of diff --> lis.
#include<algorithm>
#include<unordered_map>

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        int max_lis = 0;
        vector<unordered_map<int,int>> memo(n);
        for(int i=0;i<n;i++){
            //self memo[i][any_diff] = 1;

            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                if(memo[j].count(diff) == 0)
                    memo[i][diff] = max(
                        memo[i][diff], //0 if not exist
                        2
                    );
                else
                    memo[i][diff] = max(
                        memo[i][diff], //0 if not exist
                        1 + memo[j][diff]
                    );
                
                max_lis = max(
                    max_lis,
                    memo[i][diff]
                );
            }
        }

        return max_lis;
    }
};
