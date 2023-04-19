//m1
//divide and conquer has only 1 branch, so pass digit vector by reference (non-constant), not pass by value
#define MOD 1337
#include<algorithm>
#include<assert.h>
class Solution {
public:
    inline void significant0(vector<int>& digit){
        while(digit.size() != 0 && digit.back() == 0) digit.pop_back();
    }

    inline void subtract1(vector<int>& digit){
        //subtract 1 only when odd
        assert(digit.size() != 0);
        digit.front() -= 1;

        significant0(digit);
    }

    inline void division(vector<int>& digit, const int& y=2){
        int remainder = 0;
        int denominator;
        for(int i=digit.size()-1;i>=0;i--){
            denominator = remainder*10 + digit[i];
            digit[i] = denominator / y;
            remainder = denominator % y;
        }

        significant0(digit);
    }

    inline bool is_zero(const vector<int>& digit){
        return digit.size() == 0;
    }

    inline bool divisible_by2(const vector<int>& digit){
        return is_zero(digit) || digit.front() % 2 == 0;
    }

    long long pow_divide_conquer(const long long& a, vector<int>& digit){
        if(a == 0)return 0;
        if(is_zero(digit))return 1;

        if(divisible_by2(digit)){
            division(digit);
            long long half = pow_divide_conquer(a, digit);
            return (half*half)%MOD;
        }else{
            subtract1(digit);
            long long minus1 = pow_divide_conquer(a, digit);
            return (a*minus1)%MOD;
        }
    }

    int superPow(int a, vector<int>& b) {
        reverse(b.begin(), b.end());

        significant0(b);

        return (int)pow_divide_conquer((long long)a, b);
    }
};
