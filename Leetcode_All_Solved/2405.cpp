#define ALPHABET 26
#include<bitset>
class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        while(i < n){
            cnt++;
            bitset<ALPHABET> bits;
            while(i < n && bits[s[i] - 'a'] == 0)
                bits[s[i++] - 'a'] = 1;
        }
        return cnt;
    }
};
