class Solution {
public:
    int reverse(int x) {
        //edge case
        if(x == 0) return 0;
        
        int sign = (x<0)? (-1):1;
        
        vector<int> digits;
        int y = x;
        while(y != 0){
            digits.push_back( abs(y%10) );
            y /= 10;
        }
        
        int int_max = (unsigned int)(1<<31) - 1;
        int int_min = (1<<31);
        
        int z = 0;
        for(const int& d: digits){
            if(sign == 1){
                if((double)int_max/(double)10 < (double)z) return 0;
                
                if(int_max - d < z*10) return 0;
                
                z = z*10 + d;
            }else{
                if((double)int_min/(double)10 > (double)z) return 0;
                
                if(int_min + d > z*10) return 0;
                
                z = z*10 - d;
            }
        }
        return (int)z;
    }
};
