class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0;i+1<n;i++) ans += abs(s[i] - s[i+1]);
        return ans;

    }
};
