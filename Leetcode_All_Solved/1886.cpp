#include<assert.h>
class Solution {
public:
    int m, n;
    inline void rotate90(vector<int>& d){
        vector<int> old(d);
        d = {-old[1], old[0]};
    }

    inline void update(int& a, int& b, vector<vector<bool>>& visited, vector<int>& d){
        int a2 = a + d[0];
        int b2 = b + d[1];
        if( !( (0<=a2 && a2<m && 0<=b2 && b2<n) && visited[a2][b2] == false ) )
            rotate90(d);

        a += d[0];
        b += d[1];
        assert( m == 1 || (0<=a && a<m && 0<=b && b<n) );
    }

    inline bool snake(const vector<vector<int>>& mat, const vector<vector<int>>& target, int x, int y, vector<int> d2){
        int a = 0, b = 0;
        vector<int> d1 = {1, 0};

        vector<vector<bool>> visited1(m, vector<bool>(n, false));
        vector<vector<bool>> visited2(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[a][b] != target[x][y])return false;
                visited1[a][b] = true;
                visited2[x][y] = true;

                //update
                update(a, b, visited1, d1);
                update(x, y, visited2, d2);
            }
        }

        return true;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        m = mat.size();
        n = mat.back().size();

        vector<int> d = {1, 0};

        if(snake(mat, target, 0, 0, d))return true;

        rotate90(d);
        if(snake(mat, target, m-1, 0, d))return true;

        rotate90(d);
        if(snake(mat, target, m-1, n-1, d))return true;

        rotate90(d);
        if(snake(mat, target, 0, n-1, d))return true;

        return false;
    }
};
