class Solution {
public:
    int minimizedStringLength(string s) {
        bool has[256] = {0};
        for(char c: s) has[c] = true;

        int ans = 0;
        for(char c='a';c<='z';c++)
            ans += has[c];
        return ans;
    }
};
