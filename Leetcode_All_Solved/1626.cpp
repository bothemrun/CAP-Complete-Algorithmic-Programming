#include<utility>
#include<algorithm>

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second != b.second)
        return a.second < b.second;//non-decreasing in age
    else 
        return a.first < b.first;
    //NOTE: for same ages, inreasing (actually non-decreasing) in score
    //NOTE: so DP LIS can choose both or the lower scorer.
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int,int>> score_age(n);
        for(int i=0;i<n;i++)
            score_age[i] = pair<int,int>(scores[i], ages[i]);
        sort(score_age.begin(), score_age.end(), cmp_fn);

        //NOTE: longest increasing subsequence (actually non-decreasing)
        vector<int> dp_ending(n);
        
        for(int i=0;i<n;i++){
            dp_ending[i] = score_age[i].first;

            for(int j=0;j<i;j++)if(score_age[j].first <= score_age[i].first)
                dp_ending[i] = max(
                    dp_ending[i],
                    dp_ending[j] + score_age[i].first
                );
        }

        return *max_element(dp_ending.begin(), dp_ending.end());
    }
};





