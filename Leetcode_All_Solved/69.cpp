class Solution {
private:
    inline bool good(const long long& x, const long long& y){
        return y*y <= x;
    }
    long long binary_search(const long long& x, long long low, long long high){
        long long mid = low + (high-low)/2;
        if(good(x, mid) && !good(x, mid+1))return mid;//applies for size 1 interval
        if(low == high)return (-1);//not here
        
        if(good(x, mid+1))return binary_search(x, mid+1, high);
        else return binary_search(x, low, mid);
    }
public:
    int mySqrt(int x) {
        return (int)binary_search(x, 0, x);
    }
};
