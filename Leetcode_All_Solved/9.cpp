#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        // to string
        string digit = to_string(x);
        bool palindrome = true;
        int i = 0, j = digit.size() - 1;
        while(i < j){
            if(digit.at(i) != digit.at(j)){
                palindrome = false;
                break;
            }
            i++;
            j--;
        }
        return palindrome;
    }
};
