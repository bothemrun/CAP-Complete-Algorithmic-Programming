class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;
        int pos = 0;
        for(const int& x: nums){
            pos += x;
            if(pos == 0) ans++;
        }

        return ans;
    }
};
