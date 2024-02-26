//m0
//O(n) dp recursion with memo

//NOTE: mixing modular & max() operations can result in wrong numerical answers.

#include<algorithm>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int mod = (int)1e9 + 7;

    vector< vector<int>* > ptr;
    vector< unordered_map<int, int> > idx;

    const long long notyet = (-1);
    vector<vector<long long>> memo;

    long long enum_dup(bool track, const int& i){
        if(i<0) return 0;

        if(memo[track][i] != notyet) return memo[track][i];

        const long long& val = ptr.at(track)->at(i);
        if(
            idx[0].count(val) != 0 &&
            idx[1].count(val) != 0
        ) return memo[track][i] = 
            val + max(
                enum_dup(track, i-1),
                enum_dup( !track, idx[!track][val] - 1 )
            );

        return memo[track][i] = val + enum_dup(track, i-1);
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        ptr = {&nums1, &nums2};

        idx.resize(2);
        for(int i=0;i<m;i++) idx[0][nums1[i]] = i;
        for(int i=0;i<n;i++) idx[1][nums2[i]] = i;

        memo.resize(2);
        memo[0].resize(m, notyet);
        memo[1].resize(n, notyet);

        return max(
            enum_dup(0, m-1),
            enum_dup(1, n-1)
        )%mod;
    }
};
