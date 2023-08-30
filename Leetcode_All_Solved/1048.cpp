//m0
//recursion with memo.
//O(all word * delete 1 char from the word * use hash map to check if the predecessor exists) = O(NLL)

//they are acyclic and form a topological order,
//since the length difference must be 1.

#include<unordered_map>
#include<unordered_set>
#include<algorithm>

class Solution {
public:
    unordered_set<string> words_set;
    unordered_map<string, int> memo;

    int topo_order(const string& word){
        if(memo.count(word) != 0) return memo[word];

        int lis = 1;
        for(int i=0;i<(int)word.size();i++){
            string pred = word.substr(0, i) + word.substr(i+1);
            if(words_set.count(pred) == 0) continue;

            lis = max(
                lis,
                1 + topo_order(pred)
            );
        }
        return memo[word] = lis;
    }

    int longestStrChain(vector<string>& words) {
        for(const string& w: words) words_set.insert(w);

        int max_lis = 1;
        for(const string& w: words)
            max_lis = max(
                max_lis,
                topo_order(w)
            );
        return max_lis;
    }
};
