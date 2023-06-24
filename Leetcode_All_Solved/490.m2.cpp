//m2
//instead of connecting cells beside the walls, 
//traverse a cell by 1 step.
//O(m*n * (m+n))

//bfs better for exploring.
#define max_n 101
#include<queue>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze.back().size();
        

        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};
        q.push(pair<int,int>(start[0], start[1] ));
        inq[start[0]][start[1]] = true;

        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();
                if(i==destination[0] && j==destination[1] ) return true;

                for(int k=0;k<dx.size();k++){
                    int x = i, y = j;
                    while(true){
                        int a=x+dx[k];
                        int b=y+dy[k];
                        if(!( 0<=a && a<m && 0<=b && b<n )) break;
                        if(maze[a][b] == 1) break;

                        x = a;
                        y = b;
                    }

                    if(inq[x][y] == true) continue;

                    q.push(pair<int,int>(x, y));
                    inq[x][y] = true;
                }
            }
        }

        return false;
    }
};
