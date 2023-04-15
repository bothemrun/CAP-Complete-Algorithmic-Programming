#include<stack>
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<int> left_idx;
        vector<vector<int>> remove;
        for(int i=0;i<n;i++){
            if(s[i] == '(') left_idx.push(i);
            else{
                if(left_idx.size() == 1) remove.push_back({left_idx.top(), i});
                left_idx.pop();
            }
        }

        string ans = "";
        for(const vector<int>& re: remove)
            ans += s.substr(re[0]+1, re[1]-1 - re[0] );
        return ans;
    }
};
