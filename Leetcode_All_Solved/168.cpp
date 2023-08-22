#include<algorithm>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int x = columnNumber;
        while(x > 0){
            ans += ( 'A' + (x-1)%26 );

            x -= 1;
            x /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
