//m1
//O(n^2) by smallest heap of fixed size (but implementation is max heap), space optim bottom up dp

//1 column can't coincide with 2 columns of another row, so enough.
#define IDX(i) ((i)%2) //wrong: (i%2)
#include<queue>
#include<utility>
#include<assert.h>

class cmp_class{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;//max heap, sink down
    }
};

class Smallest_Fixed{
private:
    const int fixed_size = 2;
    //NOTE: max heap, not min
    priority_queue< pair<int,int>, vector<pair<int,int>>, cmp_class > maxheap[2];

public:
    void push(const int& val, const int& col, const int& row){
        maxheap[ IDX(row) ].push( pair<int,int>(val, col) );
        if(maxheap[ IDX(row) ].size() > fixed_size)
            maxheap[ IDX(row) ].pop();
    }

    pair<int,int> smallest2(const int& row){
        return maxheap[ IDX(row) ].top();
    }
    pair<int,int> smallest(const int& row){
        assert(maxheap[ IDX(row) ].size() == 2);

        vector<pair<int,int>> tmp;
        while( maxheap[ IDX(row) ].size() != 0 ){
            tmp.push_back( maxheap[ IDX(row) ].top() );
            maxheap[ IDX(row) ].pop();
        }

        for(const auto& p: tmp)
            maxheap[ IDX(row) ].push(p);
        return tmp[1];
    }

    void clear(const int& row){
        //NOTE: crucial for space optim dp.
        //no clear(): maxheap[ IDX(row) ].clear();
        while(maxheap[ IDX(row) ].size() != 0)
            maxheap[ IDX(row) ].pop();
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        //edge case: n==1, problem for our fixed size heap
        if(n < 2) return grid.front().front();

        class Smallest_Fixed* small = new Smallest_Fixed();
        for(int j=0;j<n;j++)
            small->push(grid[0][j], j, 0);
        
        for(int i=1;i<n;i++){
            //NOTE: crucial
            small->clear(i);

            for(int j=0;j<n;j++){
                if( small->smallest(i - 1).second == j )
                    small->push(
                        grid[i][j] + small->smallest2(i - 1).first,
                        j,
                        i
                    );
                else
                    small->push(
                        grid[i][j] + small->smallest(i - 1).first,
                        j,
                        i
                    );
            }
        }

        return small->smallest(n-1).first;
    }
};
