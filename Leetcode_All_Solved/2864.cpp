class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt1 = 0;
        for(int i=0;i<n;i++)if(s[i] == '1') cnt1++;

        string ans = "";
        for(int i=0;i<cnt1-1;i++) ans += '1';
        for(int i=0;i<n-cnt1;i++) ans += '0';
        ans += '1';
        return ans;
    }
};
