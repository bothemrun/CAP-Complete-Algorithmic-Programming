//O(nlogn) due to sorting
//A. optimal strategy by greedy & sorting.
//B. two pointer
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());

        int max_score = 0;
        int score = 0;

        int up=0, down=n-1;
        while(up <= down){
            while(up <= down && tokens[up] <= power){
                power -= tokens[up];
                up++;
                score++;
            }

            max_score = max(max_score, score);

            if(!(score >= 1)) break;
            while(up <= down && score >= 1 && !(tokens[up] <= power) ){
                score--;
                power += tokens[down];
                down--;
            }
            if(!(up <= down && tokens[up] <= power)) break;
        }

        return max_score;
    }
};
