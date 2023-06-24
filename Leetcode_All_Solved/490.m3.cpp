//m3
//instead of traversing the cells by 1 step, 
//connect all the cells beside the walls.

//but instead of connecting middle cells to the wall cells as in method 0,
//just connect the starting cell to its 4 wall cells.

//but for cell (1, 3) --> (1, 0) in example 1, it's 1-way connection, 
//we use left and right arrays.

//theoretically improved from O(m*n * (m+n)) to O(m*n)

#define max_n 101
#include<queue>
#include<utility>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define bound_wall (-2)
enum{
    Left,
    Right,
    Top,
    Bottom
};

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};
    vector<vector< vector< pair<int,int> > >> adj;

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze.back().size();

        adj.resize(m, vector< vector<pair<int,int>> >(n) );

        //NOTE: bounds
        vector<vector<vector<int>>> bound(m, vector<vector<int>>(n, vector<int>(4, -3)) );

        for(int i=0;i<m;i++){
            int left = bound_wall;
            for(int j=0;j<n;j++){
                if(maze[i][j] == 0){
                    if(left == bound_wall) left = j;

                    bound[i][j][Left] = left;
                }else{
                    left = bound_wall;
                }
            }

            int right = bound_wall;
            for(int j=n-1;j>=0;j--){
                if(maze[i][j] == 0){
                    if(right == bound_wall) right = j;

                    bound[i][j][Right] = right;
                }else{
                    right = bound_wall;
                }
            }
        }

        for(int j=0;j<n;j++){
            int top = bound_wall;
            for(int i=0;i<m;i++){
                if(maze[i][j] == 0){
                    if(top == bound_wall) top = i;

                    bound[i][j][Top] = top;
                }else{
                    top = bound_wall;
                }
            }

            int bottom = bound_wall;
            for(int i=m-1;i>=0;i--){
                if(maze[i][j] == 0){
                    if(bottom == bound_wall) bottom = i;

                    bound[i][j][Bottom] = bottom;
                }else{
                    bottom = bound_wall;
                }
            }
        }



        //NOTE: connect wall cells
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n){
                while(j<n && maze[i][j] != 0) j++;
                if(!(j<n)) break;
                int start0 = j;

                while(j+1<n && maze[i][j+1] == 0) j++;
                int end0 = j;

                if(start0 != end0){
                    adj[i][start0].push_back(pair<int,int>(i, end0));
                    adj[i][end0].push_back(pair<int,int>(i, start0));
                }

                //NOTE: connect to bound cells
                //may contains duplicate
                for(int jj: {start0, end0})
                    for(int b: {Top, Bottom}){
                        assert( maze[i][jj] == 0 );
                        assert( bound[i][jj][b] >= 0 );
                        assert( maze[ bound[i][jj][b] ][jj] == 0);
                        adj[i][jj].push_back(pair<int,int>( bound[i][jj][b], jj ));
                    }
                

                //update
                j = end0 + 1;
            }
        }

        for(int j=0;j<n;j++){
            int i=0;
            while(i<m){
                while(i<m && maze[i][j] != 0) i++;
                if(!(i<m)) break;
                int start0 = i;

                while(i+1<m && maze[i+1][j] == 0) i++;
                int end0 = i;

                if(start0 != end0){
                    adj[start0][j].push_back(pair<int,int>(end0, j));
                    adj[end0][j].push_back(pair<int,int>(start0, j));
                }

                //NOTE: connect to bound cells
                //may contains duplicate
                for(int ii: {start0, end0})
                    for(int b: {Left, Right}){
                        assert( maze[ii][j] == 0 );
                        assert( bound[ii][j][b] >= 0 );
                        assert( maze[ii][ bound[ii][j][b] ] == 0);
                        adj[ii][j].push_back(pair<int,int>( ii, bound[ii][j][b] ));
                    }

                //update
                i = end0 + 1;
            }
        }

        //NOTE: connect start cell to its 4 wall cells separately
        for(int k=0;k<di.size();k++){
            int i = start[0];
            int j = start[1];
            while(true){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) break;
                if(maze[x][y] == 1) break;

                i = x;
                j = y;
            }

            if(!( i == start[0] && j == start[1] ) ){
                adj[start[0]][start[1]].push_back(pair<int,int>(i, j));
            }
        }


        //NOTE: bfs
        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};
        q.push(pair<int,int>(start[0], start[1]));
        inq[start[0]][start[1]] = true;

        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                if(i == destination[0] && j == destination[1]) return true;

                for(const auto& [x, y]: adj[i][j]){
                    if(inq[x][y]) continue;

                    q.push(pair<int,int>(x, y));
                    inq[x][y] = true;
                }
            }
        }

        return false;
    }
};
