#include<assert.h>
class Solution {
public:
    inline int power(const int& a, const int& b){
        assert(!(a==0 && b==0));
        if(a==0) return 0;
        if(b==0) return 1;

        int mid = power(a, b/2);
        if(b%2==1) return a*mid*mid;
        else return mid*mid;
    }

    bool isArmstrong(int n) {
        vector<int> digit;
        int x = n;
        while(x != 0){
            digit.push_back(x%10);
            x /= 10;
        }

        long long sum = 0;
        for(const int& d: digit) sum += power(d, digit.size());

        return sum == n;
    }
};
