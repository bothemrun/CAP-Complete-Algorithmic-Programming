//O(nlogn) by sorting & binary searches

//greedy part: first sort and make them unique
//since duplicate numbers must use 1 operation.

#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> uni;
        for(const int& x: nums)if(uni.size()==0 || uni.back() != x)
            uni.push_back(x);
        int uni_size = (int)uni.size();


        int min_op = n+2;
        for(int i=0;i<uni_size;i++){
            const int& start = uni[i];
            int end = start + (n-1);

            int idx = upper_bound(uni.begin() + i, uni.end(), end) - uni.begin();
            int within_idx = idx-1;

            int within_cnt = within_idx - (i-1);
            assert(within_cnt >= 0);

            min_op = min(min_op, uni_size - within_cnt);
        }

        //NOTE: originally duplicate numbers
        return min_op + (n - uni_size);
    }
};
