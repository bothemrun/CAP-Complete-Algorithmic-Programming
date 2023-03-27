#include<algorithm>
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        while(i < n){
            int end = (i + k < n)? (i+k):n;
            reverse(s.begin() + i, s.begin() + end );

            i += 2*k;
        }
        return s;
    }
};
