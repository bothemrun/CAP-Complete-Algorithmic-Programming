//O(tree * bfs) = O(mn * mn) = O(6e6)

#define P2I pair<int,int>
#include<queue>
#include<utility>

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    inline int bfs(const vector<vector<int>>& forest, const int& start0, const int& start1, const int& goal0, const int& goal1){
        
        queue<P2I> q;
        vector<vector<bool>> inq(m, vector<bool>(n, false));

        q.push(P2I(start0, start1));
        inq[start0][start1] = true;

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                auto [i, j] = q.front();
                q.pop();

                if(i==goal0 && j==goal1) return level;


                for(int k=0;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];

                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(inq[x][y] == true) continue;
                    if(forest[x][y] == 0) continue;

                    inq[x][y] = true;
                    q.push(P2I(x, y));
                }
            }

            level++;
        }

        return (-1);
    }

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest.back().size();

        vector<P2I> tree;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(forest[i][j] > 1)
                tree.push_back(P2I(i, j));
        
        auto cmp_lam = [&forest](const P2I& a, const P2I& b){
            return forest[a.first][a.second] < forest[b.first][b.second];
        };
        sort(tree.begin(), tree.end(), cmp_lam);


        int ans = 0;
        int x = 0, y = 0;
        for(const auto& [i, j]: tree){
            int dist = bfs(forest, x, y, i, j);
            
            if(dist == (-1)) return (-1);

            ans += dist;

            x = i;
            y = j;
        }

        return ans;
    }
};
