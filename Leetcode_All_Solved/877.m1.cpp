//m1
//better codes than m0. O(n^2)

//just compute the max of 1 player, don't worry about whose turn.

//we don't have to return the choice taken,
//we just know the opponent will choose the min results for the opponent.

//recursion with memo.

#define notyet (-1)

class Solution {
public:
    vector<vector<int>> memo;

    int enum_opponent_min(const vector<int>& piles, const int& i, const int& j){
        if(i+1 == j){
            return max(piles[i], piles[j]);
        }
        if(!(i+1 < j)) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        int opponent1 = enum_opponent_min(piles, i+1, j);
        int opponent2 = enum_opponent_min(piles, i, j-1);

        if(opponent1 < opponent2)
            return memo[i][j] = piles[i] + min(
                enum_opponent_min(piles, i+1+1, j),
                enum_opponent_min(piles, i+1, j-1)
            );
        else
            return memo[i][j] = piles[j] + min(
                enum_opponent_min(piles, i+1, j-1),
                enum_opponent_min(piles, i, j-1-1)
            );
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n, vector<int>(n, notyet));

        return enum_opponent_min(piles, 0, n-1) > min(
            enum_opponent_min(piles, 0, n-2),
            enum_opponent_min(piles, 1, n-1)
        );
    }
};
