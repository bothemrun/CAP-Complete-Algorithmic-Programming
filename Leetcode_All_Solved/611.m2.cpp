//m2
//two pointers. Leetcode 3Sum two pointers interpretation
//put squeezing pointers on 1 side, and enumeration pointer on the other side of the equation, and squeeze utilizing monotonicity
#include<algorithm>
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int k=2;k<n;k++){
            //NOTE:above
            int j = k;
            for(int i=0;i<k;i++){
                while(i < j-1 && nums[i]+nums[j-1] > nums[k]) j--;
                if(i < j && j != k)ans += (k-1) - (j-1);//NOTE
                else if(i < k-1 && j != k) ans += (k-1) - i;//NOTE
                //printf("%d %d %d %d\n", i, j, k, ans);
            }
        }
        return ans;
    }
};
