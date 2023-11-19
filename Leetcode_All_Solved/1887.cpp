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
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;//no overflow since (5e4)^2 < INT_MAX
        int i=n-1;
        while(i>=0){
            int j=i;
            while(j-1>=0 && nums[i] == nums[j-1]){
                j--;
            }

            //[j, end] the same
            if(j==0) break;

            ans += n - j;

            //update
            i = j-1;
        }

        return ans;
    }
};
