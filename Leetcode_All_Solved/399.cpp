#include<unordered_map>
class Solution {
private:
    unordered_map<string, unordered_map<string,double> > adjlist;//u_str -> v_str -> weight
    bool dfs(string u, const string& target, unordered_set<string>& visited, double& result, double cur_result=1.0){
        if(adjlist.count(u) == 0)return false;
        if(visited.count(u) == 1)return false;
        visited.insert(u);
        if(u == target){
            result = cur_result;
            return true;
        }
        
        for(unordered_map<string,double>::iterator it = adjlist[u].begin();it != adjlist[u].end();it++){
            if( dfs(it->first, target, visited, result, cur_result * it->second) == true )return true;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<values.size();i++){
            string var1 = equations[i][0];
            string var2 = equations[i][1];
            
            auto it1 = adjlist.find(var1);
            if(it1 == adjlist.end()) adjlist[var1] = unordered_map<string,double>({{var2, values[i]}});
            else it1->second[var2] = values[i];
            
            auto it2 = adjlist.find(var2);
            if(it2 == adjlist.end()) adjlist[var2] = unordered_map<string,double>({{var1, 1.0/values[i]}});
            else it2->second[var1] = 1.0/values[i];
        }
        
        
        vector<double> ans;
        for(const vector<string>& q:queries){
            string var1 = q[0];
            string var2 = q[1];
            unordered_set<string> visited;
            double result;
            if(dfs(var1, var2, visited, result) == true)ans.push_back(result);
            else ans.push_back((-1.0));
        }
        return ans;
    }
};
