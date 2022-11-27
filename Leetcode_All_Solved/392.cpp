class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i=0;i<s.size();i++){
            while( j < t.size() && s[i] != t[j] ) j++;
            if(j == t.size())return false;
            j++;
        }
        return true;
    }
};
