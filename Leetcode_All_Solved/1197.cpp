//NOTE: use vector, instead of hash maps for the inqueue mark.
//NOTE: use the symmetry property, so coordinates out of the vector bound can be replaced by coordinates of in the vector bound.

#define offset 300
#define max_xy (2*offset + 1)
#include<queue>
#include<utility>
#include<assert.h>

class Solution {
public:
    inline int to_offset(const int& x){
        return x+offset;
    }
    inline bool in_bound(const int& x){
        return 0<=x && x<max_xy;
        //NOTE: not x <= max_xy
    }

    vector<pair<int,int>> move;
    inline void knight_move(){
        vector<int> two = {-2, 2};
        vector<int> one = {-1, 1};
        for(const int& i: two)
            for(const int& j: one){
                move.push_back(pair<int,int>(i, j));
                move.push_back(pair<int,int>(j, i));
            }
    }

    int minKnightMoves(int x, int y) {
        knight_move();

        int start_i = to_offset(0), start_j = to_offset(0);
        x = to_offset(x);
        y = to_offset(y);

        queue<pair<int,int>> q;
        vector<vector<bool>> inqueue(max_xy, vector<bool>(max_xy, false));
        q.push(pair<int,int>(start_i, start_j));
        inqueue[start_i][start_j] = true;
        int level = 0;

        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();
                if(i == x && j == y)return level;

                for(const auto& [di, dj]: move){
                    int i2 = i+di;
                    int j2 = j+dj;
                    if(!( in_bound(i2) && in_bound(j2) )) continue;
                    if(inqueue[i2][j2]) continue;

                    q.push(pair<int,int>(i2, j2));
                    inqueue[i2][j2] = true;
                }
            }

            level++;
        }

        assert(false);
        return (-1);
    }
};
