class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a||b||c){
            if(c%2 == 0) cnt += a%2 + b%2;
            else cnt += (a%2==0 && b%2==0);

            a /= 2;
            b /= 2;
            c /= 2;
        }
        return cnt;
    }
};
