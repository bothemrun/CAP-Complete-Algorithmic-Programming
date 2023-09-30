//O(mnk) bfs with k as the additional state variable, (i, j, k)

//for visiting an obstacle twice after the elimination in the first visit,

//that must be a bad choice, compared to not visiting it twice.

//so don't worry about double elimination of the same obstacle.

#define maxn 41
#define maxk (40*40+1)
#define P2I pair<int,int>
#define P3I pair<int, P2I >
#include<queue>
#include<utility>

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        bool inq[maxn][maxn][maxk] = {0};
        queue< P3I > q;

        q.push( P3I( k, P2I(0, 0) ) );
        inq[0][0][k] = true;

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                P3I p3i = q.front();
                q.pop();

                int elim = p3i.first;
                auto [i, j] = p3i.second;

                if(i==m-1 && j==n-1) return level;


                for(int k=0;k<(int)di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    //NOTE: don't worry about double elimination of the same obstacle. see notes above.
                    int new_elim = elim - grid[x][y];
                    if(new_elim < 0) continue;
                    if(inq[x][y][new_elim] == true) continue;

                    inq[x][y][new_elim] = true;
                    q.push( P3I(new_elim, P2I(x, y) ) );
                }
            }

            level++;
        }

        return (-1);
    }
};
