static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<vector<int>> char2an;
    
    void backtrack(vector<int>& parent, const string& s, const vector<vector<int>>& al, int node){
        if(char2an[ s[node] ].size() != 0){
            parent[node] = char2an[ s[node] ].back();
        }
        char2an[ s[node] ].push_back(node);
        
        for(const int& child: al[node]){
            backtrack(parent, s, al, child);
        }
        
        assert( char2an[ s[node] ].size() && char2an[ s[node] ].back() == node );
        char2an[ s[node] ].pop_back();//backtracking
    }
    int post(const vector<vector<int>>& al, vector<int>& ans, int node){
        ans[node] = 1;
        for(const int& child: al[node]){
            ans[node] += post(al, ans, child);
        }
        return ans[node];
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n = parent.size();
        vector<vector<int>> al1;
        al1.resize(n);
        for(int i=0;i<n;i++)if(parent[i] >= 0){
            al1[ parent[i] ].push_back(i);
        }
        
        char2an.resize(256);
        backtrack(parent, s, al1, 0);
        
        vector<int> ans(n, 1);
        vector<vector<int>> al2(n);
        for(int i=0;i<n;i++)if(parent[i] >= 0){
            al2[ parent[i] ].push_back(i);
        }
        post(al2, ans, 0);
        return ans;
    }
};
