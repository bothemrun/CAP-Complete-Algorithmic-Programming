//O(n)

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ma = *max_element(nums.begin(), nums.end());

        long long ans = 0;

        //[i, j] window
        int window = 0;
        int j=(-1);
        for(int i=0;i<n;i++){
            j = max(j, i-1);

            while(j+1<n && window < k){
                if(nums[++j] == ma) window++;
            }

            if(j==n-1 && window < k) break;

            ans += (n-1) - (j-1);

            //update, drop
            if(nums[i] == ma) assert(--window >= 0);
        }

        return ans;
    }
};
