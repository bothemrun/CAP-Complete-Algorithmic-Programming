//m0
//NOTE: negative marking.
#include<assert.h>
#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(const int& x: nums){
            if(nums[ abs(x) ] < 0) return abs(x);
            nums[ abs(x) ] *= (-1);
        }
        assert(false);
        return (-1);
    }
};
