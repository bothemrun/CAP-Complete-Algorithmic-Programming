#include<ctype.h>

class Solution {
public:
    string toLowerCase(string s) {
        for(char& c: s)if(isalpha(c)){
            c = tolower(c);
        }
        return s;
    }
};
