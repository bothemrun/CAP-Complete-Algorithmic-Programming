//m2
//smallest of fixed size implemented by vector without heap, O(n^2) bottom up dp.

//a column can't coincide with 2 columns of another row, so enough.
#include<algorithm>
#include<limits.h>
#include<utility>
#include<assert.h>

#define IDX(i) ((i)%2) //wrong: (i%2)
#define Smallest(i) ( smallest[ IDX(i) ] )
#define Smallest_Size 2
class Smallest_Fixed{
private:
    static bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;//small first
    }
public:
    vector<vector<pair<int,int>>> smallest;
    Smallest_Fixed(){
        smallest.resize(2);
    }

    inline void clear(const int& i){
        for(int k=0;k<Smallest_Size;k++) Smallest(i).clear();
    }

    inline void push(const int& i, const int& val, const int& col){
        Smallest(i).push_back( pair<int,int>(val, col) );
        if(Smallest(i).size() > Smallest_Size){
            sort(Smallest(i).begin(), Smallest(i).end(), cmp_fn);
            Smallest(i).pop_back();
        }
    }

    pair<int,int> top(const int& i){
        assert(Smallest(i).size() == Smallest_Size);
        return Smallest(i)[0];
    }
    pair<int,int> top2(const int& i){
        assert(Smallest(i).size() == Smallest_Size);
        return Smallest(i)[1];
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        //edge case: n==1
        if(n < Smallest_Size) return grid.front().front();

        class Smallest_Fixed* sf = new Smallest_Fixed();
        for(int j=0;j<n;j++) sf->push(0, grid[0][j], j);

        for(int i=1;i<n;i++){
            //NOTE: crucial for space optim dp
            sf->clear(i);

            for(int j=0;j<n;j++){
                if( sf->top(i - 1).second == j )
                    sf->push(
                        i,
                        grid[i][j] + sf->top2(i - 1).first,
                        j
                    );
                else
                    sf->push(
                        i,
                        grid[i][j] + sf->top(i - 1).first,
                        j
                    );
            }
        }

        return sf->top(n-1).first;
    }
};
