//m0
//Negative Marking from editorial solution: 287. Find the Duplicate Number

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
    int firstMissingPositive(vector<int>& nums) {
        //NOTE: turn all negative and 0 into a random positive number in nums.
        int pos_mark = (-1);
        for(const int& x: nums)if(x > 0){
            pos_mark = x;
            break;
        }
        if(pos_mark == (-1)) return 1;

        for(int& x: nums)if(x<=0) x = pos_mark;


        int n = nums.size();
        //NOTE: nums[i]<0 means --> (i+1) exists.
        for(int& x: nums)if(abs(x) <= n)
            nums[ abs(x)-1 ] = ( -abs(nums[ abs(x)-1 ] ) );

        for(int i=0;i<n;i++)if(nums[i] > 0) return (i+1);
        return n+1;
    }
};
