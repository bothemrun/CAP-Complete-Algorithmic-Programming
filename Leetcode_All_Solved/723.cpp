//m0
//naive find crush without optim.
//O(mn * mn), since each find / crush takes O(mn), and there are at most O(mn) crushes.

//optim: negative marking

#include<stdlib.h>
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int m, n;

    inline bool find(vector<vector<int>>& b){
        bool found = false;

        for(int i=0;i<m;i++){
            for(int j=0;j+2<n;j++){
                int& b0 = b[i][j];
                int& b1 = b[i][j+1];
                int& b2 = b[i][j+2];

                int x = abs( b0 );

                if(x == 0) continue;
                if(!( x == abs( b1 ) && x == abs( b2 ) )) continue;

                b0 = -x;
                b1 = -x;
                b2 = -x;

                found = true;
            }
        }

        for(int j=0;j<n;j++){
            for(int i=0;i+2<m;i++){
                int& b0 = b[i][j];
                int& b1 = b[i+1][j];
                int& b2 = b[i+2][j];

                int x = abs( b0 );
                
                if(x == 0) continue;
                if(!( x == abs( b1 ) && x == abs( b2 ) )) continue;

                b0 = -x;
                b1 = -x;
                b2 = -x;

                found = true;
            }
        }

        return found;
    }

    inline void crush(vector<vector<int>>& b){
        for(int c=0;c<n;c++){

            int r = m-1;
            int positive = m-1;

            while(r>=0){

                if(b[r][c] > 0){
                    r--;
                    positive = min(positive, r);
                    continue;
                }


                //to crush, negative marking
                assert(positive <= r);

                b[r][c] = 0;

                while(positive >= 0 && !( b[positive][c] > 0) ) positive--;

                if(positive >= 0){
                    b[r][c] = b[positive][c];
                    b[positive][c] = 0;
                    positive--;
                }

                r--;
            }
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board.front().size();

        while(find(board) == true){
            crush(board);
        }
        return board;
    }
};
