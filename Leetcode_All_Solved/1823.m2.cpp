//m2
//bottom dp for optim for recursion. O(n) time, O(1) space
class Solution {
public:
    int findTheWinner(int n, int k) {
        int dp_0based = 0;//NOTE: dp[1] = 0
        for(int i=2;i<=n;i++)
            dp_0based = (dp_0based + k) % i;
            //NOTE: dp = (dp + k)%n;
        
        //NOTE: dp[n] = (dp[n-1] + k)%n
        //NOTE: f(n, k) = ( f(n-1, k) + k )%n

        return dp_0based + 1;//1-based
    }
};


/*
//m1
//O(n) recursion
class Solution {
public:
    int winner0based(const int& n, const int& k){
        if(n == 1)return 0;
        return ( winner0based(n-1, k) + k )%n;
    }
    int findTheWinner(int n, int k) {
        return winner0based(n, k) + 1;//1-based
    }
};
*/
