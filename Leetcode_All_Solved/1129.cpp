#define RED 0
#define BLUE 1
#include<queue>
#include<utility>
#include<limits.h>
class Solution {
public:
    int n;
    vector<vector<vector<int>>> adjlist;
    vector<int> dist;

    void bfs(const int& start_color){
        queue<pair<int,int>> q;
        q.push(pair<int,int>(0, start_color));

        //vector<bool> inqueue(n, false);
        //inqueue.at(0) = true;
        //NOTE: inqueue bool vector with 2 colors
        vector<vector<bool>> inqueue_color(n, vector<bool>(2, false) );
        inqueue_color.at(0)[start_color] = true;

        dist.at(0) = 0;

        int level = 1;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                //NOTE:
                auto [u, color] = q.front();
                q.pop();

                for(const int& v: adjlist[u][ (color+1)%2 ]){
                    //if(inqueue[v] == true)
                    if(inqueue_color[v][ (color+1)%2 ] == true)
                        continue;
                    

                    q.push( pair<int,int>(v, (color+1)%2 ) );
                    //inqueue[v] = true;
                    inqueue_color[v][ (color+1)%2 ] = true;
                    
                    dist[v] = min(
                        ( (dist[v]==(-1))? INT_MAX:dist[v] ),
                        level
                    );
                }
            }

            level++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        this->n = n;
        adjlist = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>() ) );
        dist = vector<int>(n, (-1));

        for(const vector<int>& e: redEdges)
            adjlist[e[0]][RED].push_back(e[1]);
        for(const vector<int>& e: blueEdges)
            adjlist[e[0]][BLUE].push_back(e[1]);
        
        bfs(RED);
        bfs(BLUE);
        return dist;
    }
};
