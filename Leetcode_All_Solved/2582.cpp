class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = n-1;
        if( (time/mod)%2 == 0 ){
            return 1 + time%mod;
        }else{
            return n - time%mod;
        }
    }
};
