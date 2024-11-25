class Solution {
public:
    bool play(int n, int last){
        if(n<=0) return false;
        
        last--;
        if(n - last < 0){
            return false;
        }
        
        if( play(n - last, last) == false){
            return true;//opponent loses
        }else{
            return false;//opponent wins
        }
    }
    bool canAliceWin(int n) {
        return play(n, 11);
    }
};
