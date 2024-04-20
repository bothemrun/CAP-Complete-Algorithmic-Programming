//m0
//O(n^2)
#include<queue>

class Solution {
public:
    vector<vector<int>> al;
    vector<int> ans;
    int n;

    inline void bfs(int start){
        queue<int> q;
        vector<bool> ever2q(n, false);

        q.push(start);
        ever2q[start] = true;

        int level = 1;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(ever2q[v] == false){
                    ever2q[v] = true;
                    q.push(v);

                    ans[level - 1]++;
                }
            }

            level++;
        }
    }

    vector<int> countOfPairs(int n, int x, int y) {
        this->n = n;

        al.resize(n);
        for(int i=0;i+1<n;i++){
            al[i].push_back(i+1);
            al[i+1].push_back(i);
        }

        if(x != y){
            al[x-1].push_back(y-1);
            al[y-1].push_back(x-1);
        }

        ans.resize(n, 0);
        for(int i=0;i<n;i++)
            bfs(i);
        return ans;
    }
};
