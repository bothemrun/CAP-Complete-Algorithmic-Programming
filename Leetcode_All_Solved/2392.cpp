//topological sort for both directed cycle detection & topological order
#define max_k 401
#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline bool toposort(const int& k, const vector<vector<int>>& edges, vector<int>& topo){
        //NOTE: ok with parallel edges, that is, non-distinct (left, right)
        vector<vector<int>> adj(k+1);
        int indegree[max_k] = {0};
        for(const vector<int>& e: edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for(int i=1;i<=k;i++)if(indegree[i] == 0)
            q.push(i);//NOTE: from 1
        
        int topo_cnt = 0;
        while(q.size()){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                int cur = q.front();
                q.pop();

                topo_cnt++;

                topo.push_back(cur);

                for(const int& nex: adj[cur])if(--indegree[nex] == 0)
                    q.push(nex);
            }
        }

        return topo_cnt == k;//NOTE: directed cycle detection
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topo_row, topo_col;
        if(!toposort(k, rowConditions, topo_row))
            return vector<vector<int>>();
        if(!toposort(k, colConditions, topo_col))
            return vector<vector<int>>();
        
        //1~k to rows/cols, 1-indexed
        vector<vector<int>> num2rowcol(2, vector<int>(k+1));
        for(int row=0;row<k;row++)
            num2rowcol[0][ topo_row[row] ] = row;
        for(int col=0;col<k;col++)
            num2rowcol[1][ topo_col[col] ] = col;
        
        vector<vector<int>> ans(k, vector<int>(k));
        for(int num=1;num<=k;num++)
            ans[ num2rowcol[0][num] ][ num2rowcol[1][num] ] = num;
        return ans;
    }
};
