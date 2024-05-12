class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();
        char diff[256] = {0};

        for(int i=0;i<n;i++) diff[s[i]] += i;

        for(int i=0;i<n;i++) diff[t[i]] -= i;

        int ans = 0;
        for(char c='a';c<='z';c++) ans += abs(diff[c]);
        return ans;
    }
};
