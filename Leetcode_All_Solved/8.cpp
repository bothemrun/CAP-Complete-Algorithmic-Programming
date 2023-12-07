#include<ctype.h>
#include<limits.h>

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int idx = 0;

        //1.
        while(idx<n && s[idx] == ' '){
            idx++;
        }

        //2.
        int sign = 1;
        if(idx<n && ( s[idx] == '-' || s[idx] == '+' ) ){
            sign = (s[idx]=='+')? 1:(-1);

            idx++;
        }

        //3. 4.
        long long num = 0;
        while(idx<n && isdigit(s[idx])){
            num *= 10LL;
            num += s[idx] - '0';

            if(sign == 1 && num > INT_MAX){
                return INT_MAX;
            }
            if(sign == (-1) && -num < INT_MIN){
                return INT_MIN;
            }

            idx++;
        }

        //5.
        num *= sign; 
        if(num > INT_MAX) num = INT_MAX;
        if(num < INT_MIN) num = INT_MIN;

        return num;
    }
};
