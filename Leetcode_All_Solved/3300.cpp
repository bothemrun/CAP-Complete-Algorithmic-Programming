class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int x: nums){
            int d = 0;
            while(x != 0){
                d += x%10;
                x /= 10;
            }
            ans = min(ans, d);
        }
        return ans;
    }
};
