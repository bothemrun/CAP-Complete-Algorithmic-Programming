//m1

//Thiking Process:

//[A] backtracking?
//1. O(2^n), no.

//[B] dp, choose or not?
//1. need the prefix sum info.
//2. O(n * all_sum), explode.

//[C] regret greedy
//1. O(n).

#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int n = nums.size();
        auto cmp = [](const int& a, const int& b){
            return a > b;//min heap
        };
        priority_queue<int, vector<int>, decltype(cmp) > minheap(cmp);

        long long prefix = 0;
        int op = 0;
        for(const int& x: nums){
            //greedy of regret greedy
            prefix += x;
            minheap.push(x);

            //regret of regret greedy
            if(prefix < 0){
                //minheap.size() msut >= 1
                int regret = minheap.top();
                minheap.pop();

                prefix -= regret;

                op++;
            }
        }

        return op;
    }
};
