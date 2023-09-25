#include<assert.h>
class Solution {
public:
    char findTheDifference(string s, string t) {
        //fast init to 0 by array
        int cnt[256] = {0};
        for(const char& c: s) cnt[c]++;

        for(const char& c: t)if(cnt[c]-- == 0)
            return c;
        assert(false);
        return 0;
    }
};
