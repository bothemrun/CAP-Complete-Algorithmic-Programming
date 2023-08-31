#include<algorithm>

class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for(const char& c: s){
            if(c == 'i'){
                reverse(ans.begin(), ans.end());
            }else{
                ans += c;
            }
        }
        return ans;
    }
};
