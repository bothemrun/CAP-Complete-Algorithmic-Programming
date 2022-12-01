//m2
//static for squares and dp vectors for optim of multiple queries.
//using static is very helpful. For comparison, just not use static in the squares and dp vector declaration.
//use C++ built-in sqrt() for optim
#include<limits.h>
class Solution {
public:
    int numSquares(int n) {
        //NOTE: static
        static vector<int> squares({1, 4, 9});
        static vector<int> dp({0});
        
        if(n < dp.size())return dp[n];
        
        //coin change
        for(int remain=dp.size();remain<=n;remain++){
            dp.push_back(INT_MAX);
            
            for(const int& coin2: squares){
                if(remain-coin2 >= 0 && dp[remain-coin2] != INT_MAX)
                    dp[remain] = min(dp[remain], 1 + dp[remain-coin2]);
            }
            for(int coin=squares.size()+1;coin<=sqrt(n);coin++){
                int coin2 = coin*coin;
                if(remain-coin2 >= 0 && dp[remain-coin2] != INT_MAX)
                    dp[remain] = min(dp[remain], 1 + dp[remain-coin2]);
            }
        }
        return dp[n];
    }
};

//by the inspiration of :
/*

class Solution {
public:
    int numSquares(int n) {
         if(n<0)
            return n;
        static vector<int> vec({0});
        if(n<vec.size())
            return vec[n];
        //超出存储
        else{
            for(int i=vec.size();i<=n;i++){
                vec.push_back(INT_MAX);
                for(int j=1;j*j<=i;j++){
                    vec[i]=min(vec[i],vec[i-j*j]+1);
                }
            }
            return vec[n];

        }
//         vector<int> vec;
        
//         for (int i = 1; i * i <= n; ++i) {
//             vec.push_back(i * i);
//         }
//         vector<int> dp(n + 1, n + 1);
//         dp[0] = 0;
        
//         for (int i = 1; i <= vec.size(); ++i) {
//             for (int j = vec[i - 1]; j <= n; ++j) {
//                 dp[j] = min(dp[j], dp[j - vec[i - 1]] + 1);                
//             }
//         }
//         return dp[n];
    }
};

*/
