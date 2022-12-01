#include<unordered_set>
class Solution {
public:
    inline int digit_square_sum(int x){
        int sum = 0;
        while(x != 0){
            int digit = x % 10;
            sum += digit * digit;
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> cycle;
        while(cycle.count(n) == 0){
            cycle.insert(n);
            n = digit_square_sum(n);
            if(n == 1)return true;
        }
        return false;
    }
};
