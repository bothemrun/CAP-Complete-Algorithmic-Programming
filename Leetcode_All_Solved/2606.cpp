//O(n) recursion with memo
#define notyet INT_MIN
#include<limits.h>
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
    int value[256] = {0};
    vector<int> memo;//no overflow

    int enum_end(const string& s, const int& i){
        if(i==(-1)) return 0;

        if(memo[i] != notyet) return memo[i];

        return memo[i] = value[ s[i] ] + 
            max( 0, enum_end(s, i-1) );
    }

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        for(char c='a';c<='z';c++)
            value[c] = (c - 'a') + 1;
        
        for(int i=0;i<(int)chars.size();i++){
            value[ chars[i] ] = vals[i];
        }

        int n = s.size();
        memo.resize(n, notyet);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(
                ans,
                enum_end(s, i)
            );
        }
        return ans;
    }
};
