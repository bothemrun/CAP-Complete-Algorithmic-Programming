//m0
//NOTE: F := 1000 function calls. O(F * FlogF) = 9.9 * 10^6 for O(FlogF) top() operation by sorting.

#include<algorithm>
#include<unordered_map>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Leaderboard {
public:
    unordered_map<int,int> id2score;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        id2score[playerId] += score;
    }
    
    int top(int K) {
        vector<int> score;
        for(const auto& [id, s]: id2score)if(s != 0) score.push_back(s);

        sort(score.begin(), score.end());

        int sum = 0;
        assert((int)score.size() >= K);
        for(int i=0, n=score.size();i<K;i++)
            sum += score[ n-1 - i ];
        return sum;
    }
    
    void reset(int playerId) {
        id2score[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
