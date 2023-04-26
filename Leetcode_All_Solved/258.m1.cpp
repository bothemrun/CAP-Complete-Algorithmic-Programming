//m1
//instead of O(1) brainteaser special case by digittal root congruence formula, this method for interviews.
class Solution {
public:
    const int b = 10;

    int addDigits(int num) {
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        if(sum/b == 0) return sum;
        else return addDigits(sum);
    }
};
