#include<unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
        for(int i=0;i<9;i++){
            unordered_set<char> m;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                else if(m.find(board[i][j]) == m.end()) m.insert(board[i][j]);
                else return false;
            }
        }
        //cols
        for(int j=0;j<9;j++){
            unordered_set<char> m;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                else if(m.find(board[i][j]) == m.end()) m.insert(board[i][j]);
                else return false;
            }
        }
        //block
        for(int bi=0;bi<3;bi++){
            for(int bj=0;bj<3;bj++){
                unordered_set<char> m;
                for(int si=0;si<3;si++){
                    for(int sj=0;sj<3;sj++){
                        int i = bi*3+si;
                        int j = bj*3+sj;
                        if(board[i][j] == '.') continue;
                        else if(m.find(board[i][j]) == m.end()) m.insert(board[i][j]);
                        else return false;
                    }
                }
            }
        }
        
        return true;
    }
};
