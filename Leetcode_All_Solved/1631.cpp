//m0
//priority queue of diff, in queue visited mark of all cells of all directions.

//O(mn log(mn)) = O(mn log( max(m, n) ))

#define maxn 100
#define max_dir 4
#define PII pair<int,int>
#define IDX(i, j) (i*n + j)

#include<utility>
#include<queue>
#include<stdlib.h>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const PII& a, const PII& b){
        return a.first > b.first;//min heap
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        priority_queue<PII, vector<PII>, cmp_class> minheap;
        bool inq[maxn][maxn][max_dir] = {0};

        minheap.push( PII(0, IDX(0, 0) ) );
        for(int k=0;k<max_dir;k++) inq[0][0][k] = true;
        
        int max_diff = 0;
        while(true){
            assert(minheap.size());
            auto [diff, idx] = minheap.top();
            minheap.pop();

            max_diff = max(max_diff, diff);

            int i = idx / n;
            int j = idx % n;
            if(i==m-1 && j==n-1) return max_diff;

            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                if(inq[x][y][k]) continue;

                inq[x][y][k] = true;

                minheap.push( PII(
                    abs( heights[i][j] - heights[x][y] ),
                    IDX(x, y)
                ) );
            }
        }

        assert(false);
        return (-1);
    }
};
