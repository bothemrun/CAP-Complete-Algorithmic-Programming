class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<vector<int>> arr(2, vector<int>());
        int n = nums.size();
        for(const int& x: nums){
            if(x > 0) arr[0].push_back(x);
            else arr[1].push_back(x);
        }
        
        for(int i=0;i<n;i++)
            nums[i] = arr[i%2][i/2];
        return nums;
    }
};
