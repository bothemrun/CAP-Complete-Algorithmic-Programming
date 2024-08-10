//O(QN) bfs
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;
    int n;
    inline int bfs(const int src, const int dest){
        queue<int> q;
        vector<bool> ever2q(n, false);
        q.push(src);
        ever2q[src] = true;

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                if(u == dest) return level;

                for(const int& v: al[u])if(ever2q[v] == false){
                    q.push(v);
                    ever2q[v] = true;
                }
            }

            level++;
        }
        assert(false);
        return (-1);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        this->n = n;
        al.resize(n);
        for(int i=0;i+1<n;i++){
            al[i].push_back(i+1);
        }

        int qn = queries.size();
        vector<int> ans(qn);
        for(int q=0;q<qn;q++){
            al[ queries[q][0] ].push_back( queries[q][1] );
            ans[q] = bfs(0, n-1);
        }
        return ans;
    }
};
