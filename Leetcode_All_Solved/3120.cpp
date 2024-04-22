class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool has[256] = {0};
        for(const char& c: word) has[c] = true;

        int ans = 0;
        for(char c='a';c<='z';c++)if( has[c] && has[c + 'A' - 'a'] ) ans++;
        return ans;
    }
};
