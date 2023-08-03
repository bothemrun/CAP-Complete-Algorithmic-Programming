//m1
//recursion with memo. O(n * sqrt(n))
//optim from m0 O(2*n*sqrt(n)) to O(1*n*sqrt(n))
//optim with preprocessing of square computing.

#define notyet (-1)
#include<assert.h>

class Solution {
public:
    vector<int> memo;
    vector<int> square;

    bool enum_choices(const int& n){
        if(n == 0) return false;
        assert(n > 0);

        if(memo[n] != notyet) return memo[n];

        for(const int& s: square){
            if(!(s <= n)) break;

            if(enum_choices(n - s) == false)
                return memo[n] = true;
        }

        return memo[n] = false;
    }

    bool winnerSquareGame(int n) {
        memo.resize(n + 1, notyet);

        for(int i=1;i*i<=n;i++)
            square.push_back(i*i);

        return enum_choices(n);
    }
};
