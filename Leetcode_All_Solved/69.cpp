class Solution {
private:
    inline bool good(const long long& x, long long y){
        return y*y <= x;
    }
    int binary_search(const long long& x, long long low, long long high){
        //NOTE: find number y s.t. y good and (y+1) bad
        long long mid = low + (high-low)/2;
        if(good(x, mid) && !good(x, mid+1)) return mid;
        if(low > high)return (-1);
        
        if(good(x, mid)) return binary_search(x, mid+1, high);
        else return binary_search(x, low, mid);
    }
public:
    int mySqrt(int x) {
        return binary_search((long long)x, 0, (long long)x);
    }
};
