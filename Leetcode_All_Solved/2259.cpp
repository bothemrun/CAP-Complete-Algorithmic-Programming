#include<assert.h>
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int i = 0;
        while(i < n){
            while(i < n && number[i] != digit){
                i++;
            }
            int i_digit = i;

            while(i < n && number[i] == digit){
                i++;
            }

            if(!(i < n))break;

            assert(digit != number[i]);
            if(digit < number[i]){
                number.erase(i_digit, 1);
                return number;
            }
        }//big while


        for(int i=n-1;i>=0;i--)if(number[i] == digit){
            number.erase(i, 1);
            return number;
        }

        assert(false);
        return "";
    }
};
