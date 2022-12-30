class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp_no0(n+1);

        if(n == 0)return 0+1;//only {0}
        dp_no0[1] = 9;

        int cnt = 1 + dp_no0[1];
        for(int i=2;i<=n;i++){
            dp_no0[i] = dp_no0[i-1] * (9 - (i-1));
            cnt += dp_no0[i] + dp_no0[i-1] * (i-1);//insert 0
        }
        return cnt;
    }
};
