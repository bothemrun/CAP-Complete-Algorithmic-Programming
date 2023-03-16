class Solution {
public:
    inline bool palindrome(const string& s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    inline bool has_char(const string& s, char ch){
        for(const char& c: s)if(c == ch)return true;
        return false;
    }
    int removePalindromeSub(string s) {
        if(palindrome(s) == true)return 1;
        bool a = has_char(s, 'a');
        bool b = has_char(s, 'b');
        return a + b;
    }
};
