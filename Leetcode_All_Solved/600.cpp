//digit dp in O(logn)
//dp(i, pre, tight)

class Solution {
public:
    const int notyet = (-1);
    vector<vector<vector<int>>> memo;
    int digit_dp(const int& n, int i, int pre, bool tight){
        if(i<0) return 1;

        if(memo[i][pre][tight] != notyet) return memo[i][pre][tight];

        int ret = 0;
        int ith_bit = ( (n>>i) & 1 );
        int bound = (tight==true)? ith_bit:1;
        for(int b=0;b<=bound;b++){
            if(pre==1 && b==1) continue;

            ret += digit_dp(n, i-1, b, tight && b==bound);
        }
        return memo[i][pre][tight] = ret;
    }
    int findIntegers(int n) {
        int msb = 0;
        int x = n;
        while(x>0){
            msb++;
            x >>= 1;
        }

        memo.resize(32, vector<vector<int>>(2, vector<int>(2, notyet)) );
        return digit_dp(n, msb-1, 0, true);
    }
};
