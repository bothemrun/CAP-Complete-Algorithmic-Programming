//NOTE: (a)2 same: xyx (b)3 distinct: xyz
//(1.1) 2 same: y(x/z)y z(x)z.  
//(1.2) 3 distinct: (y / z)(z / x)(x / y)

//(2.1) 2 same: y(x/z)y
//(2.2) 3 distinct: (y / z)(z / x)(x / y)

//so transition (2 same) = 3*(2 same) + 2*(3 distinct)
//(3 distinct) = 2*(2 same) + 2*(3 distinct)

//init: 2 same: (x/y/z) * (2), so 3*2=6
//init: 3 distinct: (x/y/z) * (permutation of the remaining 2), so 3*2=6
#define IDX(i) ((i)%2 + 2)%2
#define mod ((int)1e9 + 7)
class Solution {
public:
    int numOfWays(int n) {
        vector<long long> dp2same(2), dp3distinct(2);
        dp2same[IDX(0)] = 6;
        dp3distinct[IDX(0)] = 6;

        for(int i=1;i<n;i++){
            dp2same[IDX(i)] = ( 3*dp2same[IDX(i-1)]%mod + 2*dp3distinct[IDX(i-1)]%mod )%mod;
            dp3distinct[IDX(i)] = ( 2*dp2same[IDX(i-1)]%mod + 2*dp3distinct[IDX(i-1)]%mod )%mod;
        }

        return ( dp2same[IDX(n-1)] + dp3distinct[IDX(n-1)] )%mod;
    }
};
