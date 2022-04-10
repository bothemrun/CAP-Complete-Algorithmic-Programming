#include<unordered_set>
#include<ctype.h>
class Solution {
private:
    inline int check_nice(const string&s, int i, int j){
        unordered_set<char> chars;
        for(int k=i;k<=j;k++)chars.insert(s[k]);
        for(unordered_set<char>::iterator it = chars.begin();it!= chars.end();it++){
            if(islower(*it) && chars.find(toupper(*it)) == chars.end() )return 0;
            if(isupper(*it) && chars.find(tolower(*it)) == chars.end() )return 0;
        }
        return j - (i-1);
    }
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int max_nice = 0;
        int max_nice_i = 0, max_nice_j = (-1);
        for(int i=0;i<n;i++)for(int j=i;j<n;j++){
            int check_nice_tmp = check_nice(s, i, j);
            if(max_nice < check_nice_tmp){
                max_nice = check_nice_tmp;
                max_nice_i = i;
                max_nice_j = j;
            }
        }
        return s.substr(max_nice_i, max_nice_j - (max_nice_i-1));
    }
};
