//m0
//backtracking with prefix to words table.
//O(tree size) * O(operation for each node) = O(26^L) * O(N * L) = O(26^L * N * L)
//, where the last L is for making the prefix.
//for building the prefix table: O(N * L)

#include<unordered_map>
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
    int L;
    vector<vector<string>> ans;

    unordered_map<string, vector<int>> prefix2words;

    inline void make_prefix_table(const vector<string>& words){
        for(int i=0;i<words.size();i++){

            string prefix = "";

            for(int j=0;j<L-1;j++){
                prefix += words[i][j];

                prefix2words[prefix].push_back(i);
            }
        }
    }

    void backtrack(const vector<string>& words, const int& row, vector<int>& ans1){
        if(row == L){
            vector<string> tmp;
            for(const int& i: ans1)
                tmp.push_back( words[i] );

            ans.push_back(tmp);
            return;
        }

        string prefix = "";
        for(const int& i: ans1)
            prefix += words[i][row];
        
        for(const int& i: prefix2words[prefix]){
            ans1.push_back(i);

            backtrack(words, row + 1, ans1);

            ans1.pop_back();
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        L = words.front().size();

        make_prefix_table(words);


        //didn't make the prefix table for the empty string.
        for(int i=0;i<words.size();i++){
            vector<int> ans1 = {i};
            
            backtrack(words, 1, ans1);
        }

        return ans;
    }
};
