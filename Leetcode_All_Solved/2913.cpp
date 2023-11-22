//m0
//O(n^2)
#define max_num 101

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;//no overflow
        for(int i=0;i<n;i++){
            int distinct = 0;
            int cnt[max_num] = {0};
            for(int j=i;j<n;j++){
                if( cnt[ nums[j] ]++ == 0){
                    distinct++;
                }

                ans += distinct*distinct;
            }
        }

        return ans;
    }
};
