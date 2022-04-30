#include<utility>
#define MAX_LEN 100
class Solution {
private:
    int rows, cols;
    inline bool in(int i, int j){
        return 0<=i && i<rows && 0<=j && j<cols;
    }
    const int visited_offset = MAX_LEN + 3;
    vector<vector<bool>> visited;
    inline bool is_visited(int i, int j){
        return visited.at(visited_offset+i).at(visited_offset+j);
    }
    inline void set_visited(int i, int j){
        visited.at(visited_offset+i).at(visited_offset+j) = true;
    }
    
    inline pair<int,int> rotate90(pair<int,int> dir){
        //rotation matrix: (i,j) --> (j, -i)
        return {dir.second, -dir.first};
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        this->rows = rows, this->cols = cols;
        visited = vector<vector<bool>>(3*visited_offset, vector<bool>(3*visited_offset, false));
        
        
        vector<vector<int>> spiral;
        pair<int,int> dir = {0, 1};
        int i = rStart, j = cStart;
        bool first_dir = true;
        while(spiral.size() < rows*cols){
            //cout << i << "," << j<< "\n";
            set_visited(i,j);
            if(in(i,j)) spiral.push_back( {i,j} );
            
            //next dir
            pair<int,int> dir90 = rotate90(dir);
            if(first_dir == false && is_visited(i+dir90.first, j+dir90.second) == false)
                dir = dir90;
            else if(first_dir == true)first_dir = false;
            i += dir.first;
            j += dir.second;
        }
        return spiral;
    }
};
