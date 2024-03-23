class Solution {
public:
    inline bool vowel(const char& c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string removeVowels(string s) {
        string ans = "";
        for(const char& c: s)if(!vowel(c))
            ans += c;
        return ans;
    }
};
