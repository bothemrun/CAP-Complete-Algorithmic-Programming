//[A] [a+(h-1) + a] * h/2 = n
//1. don't use (a+b)*(b - (a-1))/2 == n formulation.
//2. min h = 2.

//[B] upper bound
//1. the max h: when 1+2+...+h = h(h+1)/2 == n.
//2. so h = O(sqrt(2n)) = 4.5e4

//[C] [2a-1 + h]*h/2 = n
//1. [2a-1 + h] = 2n/h
//2. 2a = (1-h) * h/h + 2n/h = [ (1-h)*h + 2n ] / h

//3. a = [ (1-h)*h + 2n ] / (2h) --> if a is a positive integer


//O(sqrt(2*n)) = 4.5e4

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for(int h=1;h <= (int)( sqrt(2*n) + 2);h++){
            const int numerator = (1-h)*h + 2*n;
            const int denumerator = 2*h;

            ans += numerator > 0 && numerator % denumerator == 0;
        }
        return ans;
    }
};
