//O(nlogn) longest increasing subsequence from:

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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp_fn = [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
            //NOTE: so envelopes with the same width can't be chosen (need strictly greater)
        };
        sort(envelopes.begin(), envelopes.end(), cmp_fn);

        int n = envelopes.size();
        //longest increasing subsequence in O(nlogn) 
        //by hiepit's n-ary tree with greedy.
        vector<int> greedy_tree;
        for(const vector<int>& e: envelopes){
            int x = e[1];
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
