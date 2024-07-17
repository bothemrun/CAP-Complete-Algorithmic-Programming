//m0
//standard topological sort + cycle detection
//O(26*n)

#define color_size 26
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> al(n);
        vector<int> indegree(n, 0);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);

            indegree[e[1]]++;
        }

        queue<int> q;
        vector<int> ever2q(n, false);
        
        for(int i=0;i<n;i++)if(indegree[i] == 0){
            q.push(i);
            ever2q[i] = true;
        }
        int popped = 0;

        vector<vector<int>> cnt(n, vector<int>(color_size, 0) );
        int ans = 0;

        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                popped++;

                //can do a loop over all colors,
                //but if the remaining path doesn't have the max color,
                //we can just stop at the endpoint node with the max color.
                ans = max(ans, ++cnt[u][ colors[u] - 'a' ] );

                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 0){
                        q.push(v);
                        ever2q[v] = true;
                    }

                    for(int c=0;c<color_size;c++){
                        cnt[v][c] = max( cnt[v][c], cnt[u][c] );
                    }
                }
            }
        }
        //cycle detection
        return (popped==n)? ans:(-1);
    }
};
