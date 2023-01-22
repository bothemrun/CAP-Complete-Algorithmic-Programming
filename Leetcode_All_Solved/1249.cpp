#include<unordered_set>
#include<stack>
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        stack<int> left_paren;
        unordered_set<int> remove;
        for(int i=0;i<n;i++){
            if(s[i] == '(')left_paren.push(i);
            else if(s[i] == ')'){
                if(left_paren.size() == 0)remove.insert(i);
                else left_paren.pop();
            }
        }

        while(left_paren.size() != 0){
            remove.insert(left_paren.top());
            left_paren.pop();
        }

        string ans = "";
        for(int i=0;i<n;i++)if(remove.count(i) == 0) ans += s[i];
        return ans;
    }
};
