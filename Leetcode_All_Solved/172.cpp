#include<algorithm>
class Solution {
public:
    inline int fac(const int& n, const int& f){
        int cnt = 0;
        for(int i=f;i<=n;i+=f){
            int pow = f;
            while(pow<=i && i%pow==0){
                cnt++;
                pow *= f;
            }
        }

        return cnt;
    }
    int trailingZeroes(int n) {
        int cnt5 = fac(n, 5);
        int cnt2 = fac(n, 2);
        return min(cnt5, cnt2);
    }
};
