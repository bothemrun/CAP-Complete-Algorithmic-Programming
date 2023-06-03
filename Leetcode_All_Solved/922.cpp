//in-place
#include<assert.h>
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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=1;//even, odd
        assert(j < n);

        while(i<n && j<n){
            while(i<n && nums[i]%2 == 0) i += 2;
            while(j<n && nums[j]%2 == 1) j += 2;

            if(!(i<n && j<n)) break;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
