class Solution {
    inline bool good(const long long& num, const long long& y){
        return y*y == num;
    }
    bool binary_search(const long long& num, long long low, long long high){
        long long mid = low + (high-low)/2;
        if(good(num, mid))return true;//applies for size 1 interval
        if(low == high)return false;
        
        if(mid*mid < num)return binary_search(num, mid+1, high);
        else return binary_search(num, low, mid);
    }
public:
    bool isPerfectSquare(int num) {
        return binary_search(num, 1, num);
    }
};
