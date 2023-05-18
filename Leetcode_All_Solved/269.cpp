//m0
//use topological sort for both directed cycle detection and topo order.

//NOTE: ok with parallel edges, so don't use an adjacency matrix.
#define alphabet 26
#include<queue>
#include<bitset>
#include<algorithm>

class Solution {
public:
    string alienOrder(vector<string>& words) {
        bitset<alphabet> used;
        for(const string& w: words)
            for(const char& c: w) used[c - 'a'] = 1;
        
        vector<vector<int>> adj(alphabet);
        int indegree[alphabet] = {0};
        for(int i=0;i<words.size()-1;i++){
            //NOTE: edge case:
            bool both_same = true;

            for(int j=0;j<min(words[i].size(), words[i+1].size() );j++)
                if(words[i][j] != words[i+1][j]){
                    adj[ words[i][j] - 'a' ].push_back( words[i+1][j] - 'a' );
                    indegree[ words[i+1][j] - 'a' ]++;

                    both_same = false;
                    break;
                }
            
            //NOTE: edge case:
            if(both_same && words[i].size() > words[i+1].size()) return "";
        }
        
        string topo = "";
        queue<int> q;
        for(int i=0;i<alphabet;i++)if(used[i] && indegree[i] == 0)//NOTE: ok with parallel edges
            q.push(i);
        int topo_cnt = 0;
        while(q.size()){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                int cur = q.front();
                q.pop();

                topo_cnt++;

                topo += 'a' + cur;

                for(const int& nex: adj[cur])if(--indegree[nex] == 0)//ok with parallel edges
                    q.push(nex);
            }
        }

        if(topo_cnt != used.count()) return "";
        return topo;
    }
};
