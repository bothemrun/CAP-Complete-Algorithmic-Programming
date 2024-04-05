//O(n)
#include<ctype.h>
#include<stack>

class Solution {
public:
    inline bool good(const char& a, const char& b){
        if(tolower(a) != tolower(b)) return false;
        if(islower(a) && isupper(b)) return true;
        if(isupper(a) && islower(b)) return true;
        return false;
    }

    string makeGood(string s) {
        stack<char> sta;
        for(const char& c: s){
            if(sta.size() && good(c, sta.top() )) sta.pop();
            else sta.push(c);
        }

        string ans = "";
        while(sta.size()){
            ans += sta.top();
            sta.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
