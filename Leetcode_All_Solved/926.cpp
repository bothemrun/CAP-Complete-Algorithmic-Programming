#include<limits.h>
#include<algorithm>
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0 = 0;
        for(const char& c: s)if(c == '0')
            cnt0++;
        
        int n = s.size();
        int flip = cnt0;//NOTE: high0 = -1
        int min_flip = flip;
        for(int high0=0;high0<n;high0++){
            if(s[high0] == '0')
                flip--;
            else flip++;

            min_flip = min(min_flip, flip);
        }

        return min_flip;
    }
};
