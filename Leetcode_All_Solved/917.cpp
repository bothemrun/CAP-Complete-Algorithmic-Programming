#include<algorithm>
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<j && !isalpha(s[i]) ) i++;
            while(i<j && !isalpha(s[j]) ) j--;

            swap(s[i++], s[j--]);
        }
        return s;
    }
};
