#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int> > id2time;
        for(const vector<int>& log: logs){
            if(id2time.count(log[0]) == 0){
                id2time[log[0]] = unordered_set<int>({log[1]});
            }else{
                id2time[log[0]].insert(log[1]);
            }
        }

        vector<int> ans(k, 0);
        for(const auto& [key, val]: id2time){
            if(val.size() <= k)
                ans[val.size() - 1]++;
        }
        return ans;
    }
};
