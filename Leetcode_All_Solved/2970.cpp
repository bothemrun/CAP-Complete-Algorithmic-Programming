//m0
//O(n^3) brute force

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                //subarray to remove is [i, j]

                bool inc = true;

                if(0<=i-1 && j+1<n)
                    inc = nums[i-1] < nums[j+1];

                for(int k=0;k+1<i;k++)if(nums[k] >= nums[k+1]){
                    inc = false;
                    break;
                }
                for(int k=j+1;k+1<n;k++)if(nums[k] >= nums[k+1]){
                    inc = false;
                    break;
                }

                ans += inc;
            }
        
        return ans;
    }
};
