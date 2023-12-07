//m0
//brute force
//O(m * n)
//m := moves size, n := board size

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> b(3, vector<string>(3, " "));
        for(int i=0;i<(int)moves.size();i++){
            int r = moves[i][0];
            int c = moves[i][1];
            string player = (i%2==0)? "A":"B";
            b[r][c] = player;

            if( b[r][0] == b[r][1] && b[r][1] == b[r][2] ) return player;
            if( b[0][c] == b[1][c] && b[1][c] == b[2][c] ) return player;


            if(r==c){
                if( b[0][0]==b[1][1] && b[1][1]==b[2][2] ) return player;
            }
            if(r+c==2){
                if( b[0][2]==b[1][1] && b[1][1]==b[2][0] ) return player;
            }
        }

        return (moves.size()==9)? "Draw":"Pending";
    }
};
