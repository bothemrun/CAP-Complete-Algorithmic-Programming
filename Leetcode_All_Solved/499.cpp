//m0
/*## DFS / BFS For Shortest Path:

- actually not the vanilla dfs / bfs with the visited marks, but we explore all possible paths and prevent infinite loops by stopping extending exploring if  we can’t update it.

- But it may have bad time complexity except for some suitable situations.

- https://stackoverflow.com/a/73823487

	- Ak01 answer: https://stackoverflow.com/questions/14784753/shortest-path-dfs-bfs-or-both

- suitable example: 505. The Maze II

*/

#define impossible pair<int, string>(INT_MAX, "")
#include<queue>
#include<utility>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze.back().size();
        vector<int> di={1, 0, -1, 0};
        vector<int> dj={0, 1, 0, -1};

        vector<string> dir={"d", "r", "u", "l"};
        auto cmp_fn = [](const pair<int,string>& a, const pair<int,string>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };

        queue<pair<int,int>> q;
        vector<vector<pair<int, string>>> dist(m, vector<pair<int, string>>(n, impossible ) );

        q.push(pair<int,int>(ball[0], ball[1] ));
        dist[ball[0]][ball[1]] = pair<int, string>(0, "");
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0;k<di.size();k++){
                    bool found_hole = false;
                    int x=i, y=j, delta=0;
                    while(true){
                        //next candidates
                        int a=x+di[k];
                        int b=y+dj[k];
                        if(!(0<=a && a<m && 0<=b && b<n)) break;
                        if(maze[a][b] == 1) break;

                        //good, update
                        x=a;
                        y=b;
                        delta++;

                        //NOTE: hole
                        if(x==hole[0] && y==hole[1]){
                            pair<int, string> new_dist( dist[i][j].first + delta, dist[i][j].second + dir[k] );
                            dist[x][y] = min(
                                dist[x][y],
                                new_dist,
                                cmp_fn
                            );

                            found_hole = true;
                            break;
                        }
                    }

                    if(found_hole) continue;

                    pair<int,string> new_dist(dist[i][j].first + delta, dist[i][j].second + dir[k]);
                    if( cmp_fn( new_dist, dist[x][y] ) ){
                        dist[x][y] = new_dist;
                        q.push(pair<int,int>(x, y) );
                    }
                }//for k
            }//for l
        }

        return (dist[hole[0]][hole[1]] == impossible )? "impossible":dist[hole[0]][hole[1]].second;
    }
};
