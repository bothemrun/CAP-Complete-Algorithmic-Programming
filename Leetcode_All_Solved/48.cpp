#include<algorithm>
#include<utility>
class Solution {
private:
    int n;
    inline pair<int,int> counterclockwise(pair<int,int> xy){
        int old_y = xy.second;
        xy.second = xy.first;
        xy.first = -old_y + n-1;
        return xy;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        int block_n = n/2;// 3:1, 4:2
        for(int i=0;i<block_n;i++)for(int j=0;j<block_n;j++){
            //(x,y) --> (-y,x) --> (-y + n-1, x)
            pair<int,int> xy = {i,j};
            for(int rotate=0;rotate<3;rotate++){
                pair<int,int> xy90 = counterclockwise(xy);
                swap(matrix[xy.first][xy.second], matrix[xy90.first][xy90.second]);
                xy = xy90;//NOTE
            }
        }
        
        
        if(n%2 == 1){
            for(int i=0;i<block_n+1;i++){
                //(x,y) --> (-y,x) --> (-y + n-1, x)
                pair<int,int> xy = {i, block_n+1-1};
                for(int rotate=0;rotate<3;rotate++){
                    pair<int,int> xy90 = counterclockwise(xy);
                    swap(matrix[xy.first][xy.second], matrix[xy90.first][xy90.second]);
                    xy = xy90;//NOTE
                }
            }
        }
    }
};
