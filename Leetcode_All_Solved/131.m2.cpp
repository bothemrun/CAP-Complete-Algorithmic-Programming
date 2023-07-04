//m2
//backtrack + recursion with memo in O(2^n * n)

//directly store srings, instead of storing int optim.

#define notyet (-1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<string> part1;
    vector<vector<string>> part;
    
    vector<vector<int>> memo;
    bool is_palin(const string& s, const int& i, const int& j){
        //NOTE: so includes length 2
        if(i>=j) return true;

        if(memo[i][j] != notyet) return memo[i][j];

        if(s[i] == s[j]) return memo[i][j] = is_palin(s, i+1, j-1);
        else return memo[i][j] = false;
    }

    void backtrack(const string& s, const int& i){
        if(i==n){
            part.push_back(part1);
            return;
        }

        for(int j=i;j<n;j++)if(is_palin(s, i, j)){
            part1.push_back( s.substr(i, j - (i-1) ) );
            backtrack(s, j+1);

            part1.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();

        memo.resize(n, vector<int>(n, notyet));

        backtrack(s, 0);

        return part;
    }
};
