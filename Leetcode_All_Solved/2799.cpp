#define max_num 2001
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        //fast init to 0 by array.
        bool all_has[max_num] = {0};
        int all_distinct = 0;
        for(const int& x: nums){
            if(all_has[x] == false){
                all_distinct++;
                all_has[x] = true;
            }
        }


        int cnt[max_num] = {0};
        //[i, j] window
        int j;
        int distinct = 0;
        for(j=0;j<n;j++){

            if(cnt[ nums[j] ]++ == 0){
                distinct++;

                if(distinct == all_distinct) break;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (n-1) - (j-1);

            //update, drop
            if(--cnt[ nums[i] ] == 0){
                while(j+1<n && nums[j] != nums[i] ){
                    j++;
                    cnt[ nums[j] ]++;
                }

                if( nums[j] != nums[i] ) break;
            }

            j = max(j, i+1);
        }

        return ans;
    }
};
