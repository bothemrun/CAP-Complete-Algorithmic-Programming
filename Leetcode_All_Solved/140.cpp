#define notyet (-1)
#include<assert.h>
class Solution {
public:
    vector<int> dp_can;
    vector<vector<int>> child_word;

    bool dfs(const string& s, int high, const vector<string>& wordDict){
        if(high == (-1)){
            return true;
        }
        assert(high >= 0);

        if(dp_can[high] != notyet) return dp_can[high];

        
        //NOTE: not decreasing 1 step at a time, preventing the problems of long words in wordDict.
        bool ret = false;
        for(int i=0;i<wordDict.size();i++){
            int low = high - (wordDict[i].size()-1);
            if(low < 0) continue;

            if(wordDict[i] == s.substr(low, wordDict[i].size())){
                if(dfs(s, low-1, wordDict) == true){
                    ret |= true;
                    child_word[high].push_back(i);
                }
            }
        }

        return (dp_can[high] = ret);
    }

    inline void tree_traverse_backtrack(int high, vector<string>& ans, string& ans1, const vector<string>& wordDict){
        if(high == (-1)){
            //pack
            ans.push_back(ans1);
            return;
        }
        assert(high >= 0);


        for(int child_i: child_word[high] ){
            string insertion = wordDict[child_i];
            if(ans1 != "") insertion += " ";

            ans1.insert(0, insertion);
            tree_traverse_backtrack(high - wordDict[child_i].size(), ans, ans1, wordDict);
            ans1.erase(0, insertion.size());
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp_can = vector<int>(n, notyet);
        child_word = vector<vector<int>>(n, vector<int>());

        dfs(s, n-1, wordDict);

        vector<string> ans;
        string ans1 = "";
        tree_traverse_backtrack(n-1, ans, ans1, wordDict);
        return ans;
    }
};
