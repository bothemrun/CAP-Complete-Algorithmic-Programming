//team_cnt := votes[i].length
//O(votes.length * team_cnt) + O( team_cnt * team_cnt log (team_cnt) )

#include<algorithm>

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int team_cnt = votes.back().size();
        const int alphabet = 26;
        vector<vector<int>> rank(alphabet, vector<int>(team_cnt, 0));

        for(const string& vote: votes){
            for(int i=0;i<team_cnt;i++){
                rank[ vote[i] - 'A' ][i]++;
            }
        }

        
        auto cmp = [&rank](const char& a, const char& b){
            //vector operator<
            if(rank[a-'A'] != rank[b-'A'])
                return rank[a-'A'] > rank[b-'A'];//ranks vector
            else return a<b;//team name
        };

        auto& ans = votes.front();
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};
