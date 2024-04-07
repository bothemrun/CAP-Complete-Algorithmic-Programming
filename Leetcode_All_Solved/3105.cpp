class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && nums[j] < nums[j+1]){
                j++;
            }

            ans = max(j - (i-1), ans);

            //update
            i = j+1;
        }

        i=0;
        while(i<n){
            int j=i;
            while(j+1<n && nums[j] > nums[j+1]){
                j++;
            }

            ans = max(j - (i-1), ans);

            //update
            i = j+1;
        }

        return ans;
    }
};
