#include<ctype.h>
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first_capital = isupper(word[0]);
        //from [1, end]
        bool has_lower = false;
        bool has_upper = false;
        for(int i=1;i<word.size();i++){
            if(isupper(word[i])) has_upper = true;
            else has_lower = true;
            
            //prune
            if(has_lower && has_upper)return false;
        }

        if(first_capital && ( has_lower == false || has_upper == false) )return true;
        if(first_capital == false && has_upper == false)return true;
        return false;
    }
};
