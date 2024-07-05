class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int i=0;
        while(i<n){
            int sum = nums[i];

            int j = i;
            while(j+1<n && nums[j] < nums[j+1]){
                sum += nums[++j];
            }

            ans = max(ans, sum);

            //update
            i = j+1;
        }
        return ans;
    }
};
