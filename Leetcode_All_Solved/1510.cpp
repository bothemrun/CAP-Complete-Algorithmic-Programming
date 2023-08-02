//m0
//recursion with memo. O(n * sqrt(n))

#define notyet (-1)
#include<algorithm>
#include<assert.h>

class Solution {
public:
    vector<vector<int>> memo;

    //turn: true: alice, false: bob
    //@return: can I win? (I depend on the turn)
    bool enum_choices(const int& stone, bool turn){
        if(stone == 0){
            return memo[stone][turn] = false;
        }
        assert(stone > 0);

        if(memo[stone][turn] != notyet) return memo[stone][turn];

        for(int choice=1;choice*choice <= stone;choice++){
            if( enum_choices(stone - choice*choice, !turn) == false)
                return memo[stone][turn] = true;
        }

        return memo[stone][turn] = false;
    }

    bool winnerSquareGame(int n) {
        memo.resize(n + 1, vector<int>(2, notyet));
        return enum_choices(n, true);
    }
};
