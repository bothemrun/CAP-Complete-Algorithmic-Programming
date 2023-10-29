class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int bit=0;bit<32;bit++){
            int mask = (1<<bit);
            int cnt = 0;
            for(int x: nums)if( (x & mask) )
                cnt++;
            if(cnt >= k) ans |= mask;
        }
        
        return ans;
    }
};
