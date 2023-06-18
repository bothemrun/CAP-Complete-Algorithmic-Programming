#define max_win_cnt 2
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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int avail = 1;
        int win = nums[0];
        int win_cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == win){
                if(++win_cnt > max_win_cnt) continue;
                else swap(nums[avail++], nums[i]);
            }else{
                win = nums[i];
                win_cnt = 1;

                swap(nums[avail++], nums[i]);
            }
        }

        return avail;
    }
};
