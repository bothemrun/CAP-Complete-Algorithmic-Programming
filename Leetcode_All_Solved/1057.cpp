//NOTE: time: mnlog(mn) + mn == mn(logm + logn) + mn
#include<assert.h>
#include<stdlib.h>//abs()
#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    if(a[0] != b[0] )return a[0] < b[0];
    else if(a[1] != b[1])return a[1] < b[1];
    else return a[2] < b[2];
}

class Solution {
public:
    inline int manhattan(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = bikes.size();
        int n = workers.size();

        vector<vector<int>> dist(m*n, vector<int>(3));
        
        for(int w=0;w<n;w++)
            for(int b=0;b<m;b++)
                dist[ w*m + b ] = { manhattan(workers[w], bikes[b]), w, b};

        //NOTE: mn(logm + logn)       
        sort(dist.begin(), dist.end(), cmp_fn);

        vector<int> assign(n);
        vector<bool> bike_used(m, false);
        vector<bool> assigned(n, false);
        int i = 0;
        //NOTE: max: O(mn)
        for(int w=0;w<n;w++){
            while(i < m*n && !( bike_used[ dist[i][2] ] == false && assigned[ dist[i][1] ] == false) )
                i++;
            
            assert(i < m*n);

            bike_used[ dist[i][2] ] = true;
            assign[ dist[i][1] ] = dist[i][2];
            assigned[ dist[i][1] ] = true;
            i++;
        }
        return assign;
    }
};



