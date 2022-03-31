class Solution {
private:
    bool good(int m, const int& c){
        return (long long)m*(long long)m <= (long long)c;
    }
    int binary_transit(const int& c, int low, int high){
        if(c == 0 || c == 1)return c;
        
        int mid = low + (high-low)/2;
        if( good(mid, c) && !good(mid+1, c) )return mid;//applies for low==high
        if(low == high)return (-1);//not here
        
        if(good(mid+1, c))return binary_transit(c, mid+1, high);
        else return binary_transit(c, low, mid);
    }
public:
    bool judgeSquareSum(int c) {
        //NOTE: O( log(c) + sqrt(c) )
        //NOTE: Leetcode sqrt()
        int sqrt_c = binary_transit(c, 0, c);
        
        //NOTE: Leetcode 3Sum
        long long target = c;
        long long a = 0, b = (long long)sqrt_c;
        while(a <= b){
            if(a*a + b*b == target)return true;
            
            if(a*a + b*b < target)a++;
            else b--;
        }
        return false;
    }
};
