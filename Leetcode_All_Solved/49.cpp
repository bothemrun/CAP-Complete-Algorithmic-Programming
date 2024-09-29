//O(n * LlogL) = O(1e4 * 100log100) = O(1e6)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> sorted2i;
        for(int i=0;i<n;i++){
            string so = strs[i];
            sort(so.begin(), so.end());
            
            sorted2i[so].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(const auto& [so, v]: sorted2i){
            vector<string> cur;
            for(const int& i: v) cur.push_back(strs[i]);
            ans.push_back(cur);
        }
        return ans;
    }
};
