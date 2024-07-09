//m2

//roots (1 or 2) of the minimum height trees by topological sort == middle nodes of the diameter

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> al(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }


        //minimum height trees by topological sort
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++)
            indegree[i] = al[i].size();

        queue<int> q;
        vector<bool> ever2q(n, false);

        for(int i=0;i<n;i++)if(indegree[i] == 1){
            q.push(i);
            ever2q[i] = true;
        }

        int level = 0;
        //wrong: while(q.size() > 2){
        //NOTE: tricky, not recommended.
        //recommend using unpopped count in 310. Minimum Height Trees.
        while(q.size() >= 2){
            level++;

            int qsize = q.size();
            for(int l=0;l<qsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 1){
                        q.push(v);
                        ever2q[v] = true;
                    }
                }
            }
        }

        //edge case: n==1
        if(n==1) return 0;
        return level*2 - ( (q.size()==0)? 1:0 );
    }
};
