//m4

//[A] easy dp_ending[i] in O(n^2), now require O(nlogn) for 1964. Find the Longest Valid Obstacle Course at Each Position hard.


//[B] think of a tree:

//1. a tree actually building & forking the increasing subsequences from the root to a leaf.

//2. for [2, 6, 8, 3, 4, 5, 1], the 3 paths to any leaf are: sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1] --> for process, see hiepit's sol.


//[C] implement [B] by a tree array:

//1. for eg., for node "3", once we found the parent node "2" by binary search,

//2. don't delete another forked branch ([2, 6, 8]) from the tree array.

//3. like lazy update / lazy propagation, just keep the old forked branch.

//4. we can still fork branches on any node of the tree array. --> the order is still correct.


//[D] final answer

//1. recommend not to use ans = final tree_array.size().

//2. for more clear semantics, ans = max(forked leaf index j) for all j,
//2.a. since it's more like enumerating LIS_dp_ending[j].


//[E] lower_bound or upper_bound?

//1. strictly increasing --> lower_bound(), 'cuz we replace the iterator's value.


//[reference] hiepit's solution by greedy & binary search in O(nlogn):
//https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn

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

        int max_lis = 0;

        vector<int> tree_arr;
        for(const int& x: nums){
            //when empty, v.begin() == v.end()

            //lower_bound 'cuz it's strictly increasing.
            auto it = lower_bound(tree_arr.begin(), tree_arr.end(), x);
            if(it == tree_arr.end()){
                tree_arr.push_back(x);

                max_lis = max(max_lis, (int)tree_arr.size());
            }else{
                *it = x;

                int j = it - tree_arr.begin();
                max_lis = max(max_lis, j - (0-1) );
            }
        }
        return max_lis;
    }
};
