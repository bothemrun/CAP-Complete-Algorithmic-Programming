class Solution {
public:
    int countElements(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int ma = *max_element(nums.begin(), nums.end());

        int ans = 0;
        for(const int& x: nums){
            if(mi < x && x < ma) ans++;
        }
        return ans;
    }
};
