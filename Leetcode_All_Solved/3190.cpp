class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(const int& x: nums){
            ans += x%3 != 0;
        }
        return ans;
    }
};
