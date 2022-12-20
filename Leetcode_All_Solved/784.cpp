#include<ctype.h>
class Solution {
public:
    vector<string> ans;
    string ans1 = "";
    void dfs_tree(const string& s, const int& i){
        if(i == s.size()){
            //pack
            ans.push_back(ans1);
            return;
        }

        if(isdigit(s[i])){
            ans1 += s[i];
            dfs_tree(s, i+1);
            ans1.erase(ans1.size()-1, 1);
        }else{
            ans1 += tolower(s[i]);
            dfs_tree(s, i+1);
            ans1.erase(ans1.size()-1, 1);

            ans1 += toupper(s[i]);
            dfs_tree(s, i+1);
            ans1.erase(ans1.size()-1, 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        dfs_tree(s, 0);
        return ans;
    }
};
