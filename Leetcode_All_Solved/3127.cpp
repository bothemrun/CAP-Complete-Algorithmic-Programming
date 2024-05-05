class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i+1<3;i++)
            for(int j=0;j+1<3;j++){

                int b=0;
                for(int x=0;x<2;x++)
                    for(int y=0;y<2;y++)
                        if(grid[i+x][j+y] == 'B') b++;
                
                if(b != 2) return true;
            }
        return false;
    }
};
