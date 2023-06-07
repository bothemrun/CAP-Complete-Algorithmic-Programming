//m0
//dp end at i. recursion with memo.
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
    int paren_end_at(const string& s, const int& i){
        if(i < 0) return 0;

        if(s[i] == '(') return memo[i] = 0;
        //NOTE: base case s[i-1]: '(', s[i]: ')' already included

        if(memo[i] != notyet) return memo[i];

        memo[i] = 0;
        int left_candidate = (i-1) - paren_end_at(s, i-1);
        if(left_candidate >= 0 && s[left_candidate] == '(')
            memo[i] = 2 + paren_end_at(s, i-1) + paren_end_at(s, left_candidate - 1);
            //NOTE: crucial to extend with memo[left_candidate - 1]
            //NOTE: s[left_candidate] '(' is not matched before, 
            //NOTE: so memo[i-1] doesn't include the extension before memo[left_candidate - 1]
        
        return memo[i];
    }

    int longestValidParentheses(string s) {
        int n = s.size();

        memo.resize(n, notyet);

        int max_paren = 0;
        for(int i=0;i<n;i++)
            max_paren = max(
                max_paren,
                paren_end_at(s, i)
            );
        return max_paren;
    }
};
