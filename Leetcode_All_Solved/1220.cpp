//m0
//recursion with memo.

#define mod ((int)1e9 + 7)
#define MOD(x) ((x>=mod)? (x-mod):x)
#define notyet (-1)

class Solution {
public:
    vector<vector<int>> adj = {
        {1},
        {0, 2},
        {0, 1, 3, 4},
        {2, 4},
        {0}
    };

    vector<vector<int>> memo;
    int start_char(const int& len, const int start){
        if(len==0) return 1;

        if(memo[len][start] != notyet) return memo[len][start];

        int sum = 0;
        for(const int& next: adj[start])
            sum = MOD(
                sum +
                start_char(len-1, next)
            );
        return memo[len][start] = sum;
    }

    int countVowelPermutation(int n) {
        //len = 1 ~ n
        memo.resize(n + 1, vector<int>(adj.size(), notyet));

        int sum = 0;
        for(int start=0;start<adj.size();start++)
            sum = MOD(
                sum +
                start_char(n-1, start)
            );
        return sum;
    }
};
