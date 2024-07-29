//m2
//knapsack DP, can't use tree DP.


//instead of xor analysis, m2 is for practice.

//[A] xor property: xor is both multiplication & division.

//1. so operations on edges (a,b) & (b,c) only affects a & c.
//2. since it's connectd (tree), we can have a path connecting any 2 nodes --> operation on any 2 nodes.


//[B] knapsack dp(node, parity of operations)

//1. can't use a tree DP, 'cuz there are too many combinations of subtree parity.

//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    int k;
    const long long notyet = (-1);
    const long long impossible = LLONG_MIN;
    vector<vector<long long>> memo;

    long long knapsack(const vector<int>& nums, int i, bool parity){
        if(i==n) return (parity==false)? 0:impossible;

        if(memo[i][parity] != notyet) return memo[i][parity];

        //choose or skip
        return memo[i][parity] = max(
            nums[i] + knapsack(nums, i+1, parity),
            (nums[i]^k) + knapsack(nums, i+1, !parity)
        );
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        this->n = nums.size();
        this->k = k;

        memo.resize(n, vector<long long>(2, notyet));
        return knapsack(nums, 0, 0);
    }
};
