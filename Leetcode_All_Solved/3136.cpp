#include<ctype.h>

class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool vowel[256] = {0};
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;

        vowel['A'] = true;
        vowel['E'] = true;
        vowel['I'] = true;
        vowel['O'] = true;
        vowel['U'] = true;

        bool has_vowel = false, has_con = false;
        for(const char& c: word){
            if( !( isdigit(c) || isalpha(c) ) ) return false;

            if(isalpha(c)){
                if(vowel[c]) has_vowel = true;
                else has_con = true;
            }
        }

        return has_vowel && has_con;
    }
};
