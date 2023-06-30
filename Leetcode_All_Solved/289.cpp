//in-place: represent old / new state in bit 0 / 1
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.back().size();
        vector<int> di = {1, 0, -1, 0, 1, -1, 1, -1};
        vector<int> dj = {0, 1, 0, -1, 1, -1, -1, 1};

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                //count live neighbors
                int live_nei = 0;
                for(int k=0;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    live_nei += board[x][y] & 1;
                }

                //store next state in bit 1
                if( board[i][j] & 1 == 1 ){
                    //old live
                    if(live_nei == 2 || live_nei == 3) board[i][j] |= 2;
                }else{
                    //old dead
                    if(live_nei == 3) board[i][j] |= 2;
                }
            }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j] = ( (board[i][j] & 2) == 2)? 1:0;
                //NOTE: bitise & with == operator precedence
                //NOTE: board[i][j] = ( board[i][j] & 2 == 2 )? 1:0;
    }
};
