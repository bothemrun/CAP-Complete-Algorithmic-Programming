class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        //edge case
        if(k==0) return 1;
        
        int ans = INT_MAX;
        
        const int bit_size = 32;
        vector<int> cnt(bit_size, 0);
        int win_or = 0;
        //[i, j] window
        int j=(-1);
        for(int i=0;i<n;i++){
            //NOTE:
            j = max(j, i-1);
            while(j+1<n && win_or < k){
                j++;
                for(int b=0, mask=1;b<bit_size;b++, mask<<=1){
                    cnt[b] += ( nums[j] & mask ) != 0;
                }
                win_or |= nums[j];
            }
            
            if(j==n-1 && win_or < k) break;
            assert(i<=j);
            ans = min(ans, j - (i-1) );
            
            //update, drop
            for(int b=0, mask=1;b<bit_size;b++, mask<<=1){
                if(mask & nums[i]){
                    if(--cnt[b] == 0){
                        win_or &= (~mask);
                    }
                    assert(cnt[b] >= 0);
                }
            }
        }
        
        if(ans == INT_MAX) return (-1);
        return ans;
    }
};
