#define arithmetic(x, y) ( (x+y) * (y - (x-1)) / 2 )

class Solution {
public:
    int totalMoney(int n) {
        int ans = (n/7) * arithmetic(1, 7);
        if(n/7-1 > 0) ans += arithmetic(1, (n/7-1) ) * 7;

        for(int r=1;r<=n%7;r++){
            ans += r + (n/7);
        }
        return ans;
    }
};
