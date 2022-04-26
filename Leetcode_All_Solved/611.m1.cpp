//m1
//two pointers
#include<algorithm>
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0)continue;
            
            int max_k = i+1;
            for(int j=i+1;j<n;j++){
                while(max_k+1 < n && nums[max_k+1] < nums[i]+nums[j])max_k++;
                ans += max_k - j;
            }
        }
        return ans;
    }
};
