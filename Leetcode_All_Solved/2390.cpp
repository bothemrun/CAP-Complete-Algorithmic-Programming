#include<algorithm>
#include<stack>
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string ans = "";
        int star = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '*') star++;
            else if(star > 0) star--;
            else ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
