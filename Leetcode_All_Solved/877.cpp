//m0
//recursion with memo
#define notyet (pair<int,int>(-1,-1) )
#include<utility>
#include<assert.h>

enum{
    Front,
    Back
};
class Solution {
public:
    vector<vector< pair<int,int> >> memo;
    pair<int,int> squeeze(const vector<int>& piles, const int& i, const int& j){
        assert(i<=j && j<piles.size());

        if(i==j) return memo[i][j] = pair<int,int>(piles[i], Front);

        if(i+1 == j) return memo[i][j] = 
            (piles[i] > piles[j])?
            pair<int,int>(piles[i], Front):
            pair<int,int>(piles[j], Back);
        
        if(memo[i][j] != notyet) return memo[i][j];


        pair<int,int> bob0 = squeeze(piles, i+1, j);
        pair<int,int> bob1 = squeeze(piles, i, j-1);

        bool alice_front = bob0.first < bob1.first;
        int di = 0, dj = 0;
        if(alice_front){
            di++;
            (bob0.second == Front)? di++:dj--;
        }else{
            dj--;
            (bob1.second == Front)? di++:dj--;
        }

        return memo[i][j] = pair<int,int>(
            piles[ alice_front? i:j ] +
            squeeze(piles, i+di, j+dj).first,

            alice_front? Front:Back
        );
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n, vector<pair<int,int>>(n, notyet) );

        pair<int,int> alice = squeeze(piles, 0, n-1);
        pair<int,int> bob = 
            (alice.second == Front)?
            squeeze(piles, 0 + 1, n-1):
            squeeze(piles, 0, n-1 - 1);
        
        return alice.first > bob.first;
    }
};
