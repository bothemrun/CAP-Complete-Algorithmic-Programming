#include<algorithm>
#define MAX_WEIGHT 100000
class Solution {
private:
    int N;
    vector<vector<int>> d;
    inline void make_adjmat(const vector<vector<int>>& edges){
        //NOTE: floyd warshall init
        d = vector<vector<int>>(N, vector<int>(N, MAX_WEIGHT ));//NOTE: if INT_MAX: overflow by +
        for(int i=0;i<N;i++)d[i][i] = 0;
        
        for(const vector<int>& e:edges){
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
        }
    }
    
    inline void floyd_warshall(){
        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        N = n;
        make_adjmat(edges);
        
        floyd_warshall();
        
        int min_city_cnt = INT_MAX;
        int min_city_cnt_idx = (-1);
        for(int i=0;i<N;i++){
            int city_cnt = 0;
            for(int j=0;j<N;j++)if(d[i][j] <= distanceThreshold)city_cnt++;
            if(city_cnt <= min_city_cnt){
                min_city_cnt = city_cnt;
                min_city_cnt_idx = i;
            }
        }
        return min_city_cnt_idx;
    }
};
