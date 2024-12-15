#define tsd tuple<string, double>

class Solution {
public:
    void build_al(const vector<vector<string>>& pairs, const vector<double>& rates, unordered_map<string, vector<tsd>>& al){
        int n = pairs.size();
        assert((int)rates.size() == n);
        for(int i=0;i<n;i++){
            const string u = pairs[i][0];
            const string v = pairs[i][1];
            const double w = rates[i];
            
            al[u].push_back(tsd(v, w ));
            al[v].push_back(tsd(u, 1.0/w ));
        }
    }
    void dfs(const string node, const double cur, unordered_map<string, vector<tsd>>& al, vector<tsd>& res, unordered_set<string>& visited){
        if(visited.find(node) != visited.end()){
            return;
        }
        visited.insert(node);
        res.push_back(tsd(node, cur));
        
        for(const auto& [v, w]: al[node]){
            dfs(v, cur * w, al, res, visited);
        }
    }
    void dfs_help(const string start, const double cur, unordered_map<string, vector<tsd>>& al, vector<tsd>& res){
        unordered_set<string> visited;
        dfs(start, cur, al, res, visited);
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<tsd>> al_one;
        build_al(pairs1, rates1, al_one);
        
        vector<tsd> res_one;
        dfs_help(initialCurrency, 1.0, al_one, res_one);
        
        unordered_map<string, vector<tsd>> al_two;
        build_al(pairs2, rates2, al_two);
        double ans = 1.0;
        for(const auto& [start, cur]: res_one){
            vector<tsd> res_two;
            dfs_help(start, cur, al_two, res_two);
            for(const auto& [end, cur]: res_two){
                if(end == initialCurrency){
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
