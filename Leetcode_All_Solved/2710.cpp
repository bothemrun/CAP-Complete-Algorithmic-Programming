#include<assert.h>
class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int i;
        for(i=n-1;i>=0;i--)if(num[i] != '0')
            return num.substr(0, i+1);
        assert(false);
        return num;
    }
};
