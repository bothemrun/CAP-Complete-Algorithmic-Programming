//[A] precompute the winners
//[B] binary search

//O(N + QlogN)

#include<assert.h>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class TopVotedCandidate {
public:
    int n;
    vector<int> times;
    vector<int> winner;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        //NOTE: vector deep copy
        this->times = times;

        this->n = times.size();
        winner.resize(n);
        
        vector<int> voted(n, 0);
        int winner_id = persons.front();
        for(int i=0;i<n;i++){
            voted[ persons[i] ]++;

            if( voted[ persons[i] ] >= voted[winner_id] ){
                winner_id = persons[i];
            }

            winner[i] = winner_id;
        }
    }
    
    int q(int t) {
        int i = upper_bound(times.begin(), times.end(), t) - times.begin();
        i--;
        assert(0<=i && i<n);

        return winner[i];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
