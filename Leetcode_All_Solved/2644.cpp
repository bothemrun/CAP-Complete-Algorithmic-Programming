#include<limits.h>
#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = nums.size();
        int m = divisors.size();
        int max_score = 0, max_divisor = INT_MAX;
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++)if(nums[j]%divisors[i] == 0) cnt++;
            if(cnt > max_score){
                max_score = cnt;
                max_divisor = divisors[i];
            }else if(cnt == max_score && max_divisor > divisors[i]) max_divisor = divisors[i];
        }
        return max_divisor;
    }
};
