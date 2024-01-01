class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(const int& x: nums)if(x%2 == 0){
            if(++cnt == 2) return true;
        }
        return false;
    }
};
