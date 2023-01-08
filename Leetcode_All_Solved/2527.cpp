class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for(const int& num: nums){
            ans ^= num;
        }
        return ans;
    }
};
