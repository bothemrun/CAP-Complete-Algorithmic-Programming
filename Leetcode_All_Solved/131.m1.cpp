//m1
//backtrack + recursion with memo in O(2^n * n)

//optim: only stores indices for temporary backtracking answers.

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
    vector<int> part1;
    vector<vector<int>> part;
    
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
            part1.push_back(i);
            backtrack(s, j+1);

            part1.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();

        memo.resize(n, vector<int>(n, notyet));

        backtrack(s, 0);


        vector<vector<string>> ans;
        for(const vector<int>& part1: part){
            vector<string> ans1;
            for(int size=part1.size(), i=0;i<size;i++){
                if(i==size-1)
                    ans1.push_back( s.substr(part1[i] ) );
                else{
                    int len = ( part1[i+1]-1 ) - ( part1[i]-1 );
                    ans1.push_back( s.substr(part1[i], len) );
                }
            }

            ans.push_back(ans1);
        }

        return ans;
    }
};
