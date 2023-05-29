#define max_n 100
#include<assert.h>
enum{
    Empty,
    All1,
    All2,
    Mixed
};
class TicTacToe {
public:
    int row_state[max_n][2] = {0};
    int col_state[max_n][2] = {0};
    int dia_state[2][2] = {0};
    int n;

    TicTacToe(int n) {
        this->n = n;
    }
    
    inline int state(int state_cnt[], const int& player){
        if(state_cnt[0] == Empty){
            state_cnt[0] = player;

            state_cnt[1]++;

        }else if(state_cnt[0] == All1){

            if(player == All1)
                state_cnt[1]++;
            else
                state_cnt[0] = Mixed;
        }else if(state_cnt[0] == All2){

            if(player == All2)
                state_cnt[1]++;
            else
                state_cnt[0] = Mixed;
        }else if(state_cnt[0] != Mixed)
            assert(false);

        if(state_cnt[1] == n) return player;
        return 0;
    }
    int move(int row, int col, int player) {
        int ret;
        if( (ret = state(row_state[row], player)) > 0) return ret;
        if( (ret = state(col_state[col], player)) > 0) return ret;

        if(row == col && (ret = state(dia_state[0], player)) ) return ret;
        if(row + col == n-1 && (ret = state(dia_state[1], player)) ) return ret;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
