//NOTE: TLE if 1 new bfs for each water cell.
#include<limits.h>
#include<utility>
#include<queue>
class Solution {
public:
    int m, n;
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater.back().size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;
        vector<vector<bool>> inqueue(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(isWater[i][j]){
                q.push(pair<int,int>(i, j));
                inqueue[i][j] = true;
                dist[i][j] = 0;
            }
        
        while(q.size() != 0){
            auto [i, j] = q.front();
            q.pop();

            for(int k=0;k<di.size();k++){
                int i2 = i+di[k];
                int j2 = j+dj[k];

                if(!(0<=i2 && i2<m && 0<=j2 && j2<n) || inqueue[i2][j2] || dist[i2][j2] <= dist[i][j] + 1 )
                    continue;
                
                q.push(pair<int,int>(i2, j2));
                dist[i2][j2] = dist[i][j] + 1;
                inqueue[i2][j2] = true;
            }
        }

        return dist;
    }
};
