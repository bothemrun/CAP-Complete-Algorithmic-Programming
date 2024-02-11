//O(n)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int op=0;

        int i=0, j=n-1;
        long long left = nums.front();
        long long right = nums.back();

        //edge: ok for n == 1,
        //i=0, j=0 initially.
        while(i<j){
            if(left==right){
                left = nums.at(++i);
                right = nums.at(--j);

                continue;
            }

            op++;
            //NOTE: implicit for both left & right merged into 1 at last.
            if(left<right) left += nums.at(++i);
            else right += nums.at(--j);
        }

        return op;
    }
};
