//m0
//recursion with memo. longest increasing subsequence O(n^2)
#define notyet (-1)
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
    vector<int> memo;
    int lis(const vector<vector<int>>& pairs, const int& i){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        int this_lis = 1;//NOTE: self
        for(int j=0;j<i;j++)if(pairs[j][1] < pairs[i][0] )
            this_lis = max(this_lis, lis(pairs, j) + 1);
        return memo[i] = this_lis;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        auto cmp_fn = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];//don't care about [1]
        };
        sort(pairs.begin(), pairs.end(), cmp_fn);
        memo.resize(n, notyet);

        int max_lis = 0;
        for(int i=0;i<n;i++)
            max_lis = max(max_lis, lis(pairs, i));
        return max_lis;
    }
};
