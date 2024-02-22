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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        int i=0;
        while(i<n){
            if(nums[i] == 0){
                i++;
                continue;
            }

            int start = i;
            while(i+1<n && nums[i+1] != 0){
                i++;
            }

            ans = max(ans, i - (start-1));

            i += 2;
        }

        return ans;
    }
};
