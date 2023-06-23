//m3
//read hiepit's solution by dp, greedy & binary search:
//https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/
//improved from O(n^2) dp to O(nlogn).

//actually forking and building many subsequences like an n-ary tree.

//but with the greedy approach, append the new element to its best compatible position --> 
//which is, find the longest compatible, and replace it with this better element -->
//which is, replace the smallest element >= this new element with this new element.

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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> greedy_tree;
        
        for(const int& x: nums){
            if(greedy_tree.size() == 0 || greedy_tree.back() < x)
                greedy_tree.push_back(x);
            else{
                int idx = lower_bound(greedy_tree.begin(), greedy_tree.end(), x) - greedy_tree.begin();

                assert(idx < n);
                greedy_tree[idx] = x;
                
            }
        }

        return greedy_tree.size();
    }
};
