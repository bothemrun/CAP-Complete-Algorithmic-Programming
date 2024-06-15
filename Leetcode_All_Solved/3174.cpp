#include<ctype.h>

class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(char c: s){
            if(isdigit(c)){
                assert(ans.size());
                ans.pop_back();
            }else{
                ans += c;
            }
        }
        return ans;
    }
};
