#include<algorithm>
class Solution {
public:
    inline void split(string& s, const string& delim){
        int start = 0, end;
        while( (end = s.find(delim, start)) != string::npos){
            reverse(s.begin() + start, s.begin() + start + (end-1) - (start-1) );
            start = end + delim.size();
        }
        if(start < s.size()) reverse(s.begin() + start, s.end());
    }
    string reverseWords(string s) {
        //modified split()
        const string delim = " ";
        split(s, delim);
        return s;
    }
};
