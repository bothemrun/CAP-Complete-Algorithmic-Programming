//m2
//use Dijkstra implemented by set:
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/


//in 490. The Maze, connecting all wall cells is very slow,

//while traversing the cells by 1 step is very fast.

//the reason may be the grid size is quite small.

//so here, we traverse the cells by 1 step.

#include<set>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const { //NOTE: C++17 requires const 
        if(a[0] != b[0]) return a[0] < b[0];
        else if(a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        set<vector<int>, cmp_class> set_pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        set_pq.insert({0, start[0], start[1] });
        dist[start[0]][start[1]] = 0;

        while(set_pq.size()){
            vector<int> u = *set_pq.begin();
            set_pq.erase(u);
            int i = u[1], j = u[2];

            if(vector<int>({i, j}) == destination) return dist[i][j];

            for(int k=0;k<di.size();k++){
                int x=i, y=j, delta=0;
                while(true){
                    //candidates
                    int a=x+di[k];
                    int b=y+dj[k];
                    if(!(0<=a && a<m && 0<=b && b<n)) break;
                    if(maze[a][b] == 1) break;

                    //good, update
                    x=a;
                    y=b;
                    delta++;
                }

                if(dist[i][j] + delta < dist[x][y] ){
                    set_pq.erase( {dist[x][y], x, y} );
                    dist[x][y] = dist[i][j] + delta;
                    set_pq.insert( {dist[x][y], x, y} );
                }
            }
        }

        return (-1);
    }
};
