//m1
//problem == find a path from source to destination whose max cell is minimized.

//priority queue

#define max_n 50
#include<queue>
#include<algorithm>
#include<assert.h>

class T{
public:
    int g, i, j;
    T(const int& g, const int& i, const int& j){
        this->g = g;
        this->i = i;
        this->j = j;
    }
};

class cmp_class{
public:
    bool operator()(const T* a, const T* b){
        return a->g > b->g;//min heap
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dij = {1, 0, -1, 0, 1};

        priority_queue<T*, vector<T*>, cmp_class> minheap;
        bool inheap[max_n][max_n] = {0};
        
        minheap.push( new T(grid[0][0], 0, 0) );
        inheap[0][0] = true;

        int max_pop = grid[0][0];

        while(minheap.size()){
            T* u = minheap.top();
            minheap.pop();

            int i = u->i;
            int j = u->j;

            max_pop = max(max_pop, u->g );

            if(i==n-1 && j==n-1) return max_pop;


            for(int k=0;k<4;k++){
                int x = i+dij[k];
                int y = j+dij[k+1];

                if(!(0<=x && x<n && 0<=y && y<n)) continue;
                if(inheap[x][y]) continue;


                minheap.push( new T(grid[x][y], x, y) );
                inheap[x][y] = true;
            }
        }

        assert(false);
        return (-1);
    }
};
