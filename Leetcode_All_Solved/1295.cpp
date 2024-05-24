class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(const int& x: nums){
            if(to_string(x).size() % 2 == 0) ans++;
        }
        return ans;
    }
};
