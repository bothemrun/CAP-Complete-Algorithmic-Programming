#include<assert.h>
#include<algorithm>
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_score = (-1);
        int score = 0;
        for(int i=0;i<k;i++) score += cardPoints[i];

        for(int back_size=0;back_size<=k;back_size++){
            max_score = max(max_score, score);

            if(back_size == k) break;
            //update for next
            assert(n-1 - back_size >= 0 && k-1 - back_size >= 0);
            score += cardPoints.at(n-1 - back_size) - cardPoints.at(k-1 - back_size);
        }

        return max_score;
    }
};
