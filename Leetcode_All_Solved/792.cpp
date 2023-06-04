//m0
//NOTE: basically it's trie traversal in parallel.

//s is large. O(s.size() + sum of words.size()), keep tracking of multiple suffixes simultaneously

//further use index instead of the real suffix string to represent the suffixes.
#define alphabet 26
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> parallel_trienode(alphabet);
        for(int i=0;i<words.size();i++)
            parallel_trienode.at( words[i].front() - 'a' ).push_back( pair<int,int>(i, 0) );

        int cnt = 0;
        for(const char& c: s){
            vector<pair<int,int>> repeated_char;

            for(const auto& [i, j]: parallel_trienode.at(c - 'a') ){
                if(j+1 == words[i].size()) cnt++;
                else if(c == words[i][j+1]) repeated_char.push_back( pair<int,int>(i, j+1) );
                else parallel_trienode.at( words[i][j+1] - 'a' ).push_back( pair<int,int>(i, j+1) );
            }

            //NOTE:
            parallel_trienode.at(c - 'a').clear();
            parallel_trienode.at(c - 'a') = repeated_char;
        }

        return cnt;
    }
};
