//m0
#include<unordered_map>
#include<unordered_set>
#include<assert.h>
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        unordered_set<string> ans_set;
        
        //name --> (time in int minutes, count within its 1 hour period)
        unordered_map< string, unordered_map<int,int> > time2cnt;
        unordered_map< string, unordered_map<int,int> > self_time2cnt;
        
        for(const vector<string>& at: access_times){
            const string& name = at[0];
            const string& time_s = at[1];
            int new_time = stoi( time_s.substr(0, 2) ) * 60 + stoi( time_s.substr(2) );
            
            int new_cnt = 1;//self
            if(self_time2cnt[name][new_time] != 0){
                //only selves
                new_cnt = 1 + self_time2cnt[name][new_time];
                self_time2cnt[name][new_time] = new_cnt;
                
                time2cnt[name].erase(new_time);
            }else{
                self_time2cnt[name][new_time] = 1;//self only 1
            }

            
            for(auto& [old_time, old_cnt]: time2cnt[name]){
                if(old_time <= new_time && new_time <= old_time+59){
                    old_cnt++;
                    if(old_cnt >= 3){
                        ans_set.insert(name);
                    }
                }
                
                if(new_time <= old_time && old_time <= new_time+59){
                    //new_cnt++;
                    assert(self_time2cnt[name][old_time] != 0);
                    new_cnt += self_time2cnt[name][old_time];
                    
                    if(new_cnt >= 3){
                        ans_set.insert(name);
                    }
                }
            }
            
            time2cnt[name][new_time] = new_cnt;
        }
        
        vector<string> ans;
        for(const string& name: ans_set)
            ans.push_back(name);
        return ans;
    }
};
