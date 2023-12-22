#include<algorithm>
class Solution {
public:
    int maxScore(string s) {
        int all1 = 0;
        for(const char& c: s)if(c == '1')
            all1++;
        
        int cnt0 = 0, cnt1 = 0;
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i] == '0') cnt0++;
            else cnt1++;

            ans = max(ans, cnt0 + (all1 - cnt1) );
        }
        return ans;
    }
};
