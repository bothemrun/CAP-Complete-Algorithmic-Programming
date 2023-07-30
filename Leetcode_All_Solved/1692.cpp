//m0
//NOTE: to handle the duplicates, the use the uniqueness of each candy (bags have no uniqueness).

//NOTE: we can't first distribute k candies to k bags either.
//NOTE: 'cuz we can't tell if the case (1) (2, 3) comes from the pre-distribution of (1) (2) or (1) (3)


//NOTE: so for memo[b][c] with b <= c,
//we can form the boundaries of the matrix by base cases of b==c and b==0.

#define notyet (-1)
#define mod ((long long)1e9 + 7)

class Solution {
public:
    vector<vector<long long>> memo;

    long long use_candy_uniqueness(const long long& bag, const long long& candy){

        if(bag == 0) return 0;
        if(bag == candy) return 1;

        if(memo[bag][candy] != notyet) return memo[bag][candy];

        return memo[bag][candy] = (
            //this candy in a bag alone.
            use_candy_uniqueness(bag-1, candy-1) +
            //this candy to other bags, which already nonempty
            ( use_candy_uniqueness(bag, candy-1) * bag )%mod
        )%mod;
    }

    int waysToDistribute(int n, int k) {
        memo.resize(k+1, vector<long long>(n+1, notyet) );
        return (int)use_candy_uniqueness(k, n);
    }
};
