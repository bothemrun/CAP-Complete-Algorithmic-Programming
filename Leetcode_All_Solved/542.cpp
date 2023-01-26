#define notyet (-1)
#include<queue>
#include<utility>
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.back().size();
        vector<vector<int>> dist0(m, vector<int>(n, notyet));

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(mat[i][j] == 0){
                dist0[i][j] = 0;
                q.push(pair<int,int>(i, j));
            }
        
        vector<int> di = {1, -1, 0, 0};
        vector<int> dj = {0, 0, 1, -1};

        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0;k<di.size();k++){
                    int x = i + di[k];
                    int y = j + dj[k];
                    if(!(0<=x && x<m && 0<= y && y<n))continue;
                    if(dist0[x][y] != notyet)continue;
                    dist0[x][y] = dist0[i][j] + 1;
                    q.push(pair<int,int>(x, y));
                }
            }
        }

        return dist0;
    }
};
