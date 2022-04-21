/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
#define HIGH 1000
#define LOW 1
class Solution {
private:
    int binary_bound(const int& z, const int& x, int low, int high, int left_right, CustomFunction& cf){
        //if(low < LOW || high > HIGH)return (-1);
        int mid = low + (high-low)/2;
        if(left_right == 1 && mid==HIGH && cf.f(x, HIGH) == z)return HIGH;
        if(left_right == 0 && mid==LOW && cf.f(x, LOW) == z)return LOW;
        
        if(left_right == 1 && cf.f(x, mid) == z && cf.f(x, mid+1) != z)return mid;
        //if(left_right == 0 && cf.f(x, mid) != z && cf.f(x, mid+1) == z)return mid+1;
        if(left_right == 0 && cf.f(x, mid-1) != z &&  cf.f(x, mid) == z)return mid;
        
        if(low == high)return (-1);
        
        if(cf.f(x, mid) > z)return binary_bound(z, x, low, mid, left_right, cf);
        else return binary_bound(z, x, mid+1, high, left_right, cf);
    }
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> xy;
        for(int x=LOW;x<=HIGH;x++){
            if(customfunction.f(x, 1) > z)break;
            int y_low = binary_bound(z, x, LOW, HIGH, 0, customfunction);
            int y_high = binary_bound(z, x, LOW, HIGH, 1, customfunction);
            //printf("%d %d %d\n",x,y_low, y_high);
            if(y_low > 0 && y_high > 0){
                for(int y_in=y_low;y_in<=y_high;y_in++)
                    xy.push_back( {x, y_in} );
            }
        }
        return xy;
    }
};
