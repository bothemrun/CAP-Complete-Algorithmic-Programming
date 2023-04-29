//NOTE: lambda expression for external variables for custom sort() compare function.
#include<algorithm>
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), 
            [k](const vector<int>& a, const vector<int>& b){
                return a.at(k) > b.at(k);
            }
        );

        return score;
    }
};
