#include<assert.h>
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        int repeat = numRows*2 - 2;
        if(repeat == 0)return s;

        assert(repeat > 0);
        for(int i=0;i<s.size();i++){
            int pos = i%repeat;
            if(pos < numRows){
                rows[pos] += s[i];
            }else{
                rows[ (numRows-1) - ( pos - (numRows-1) ) ] += s[i];
            }
        }

        string ans = rows.front();
        for(int i=1;i<numRows;i++)
            ans += rows[i];
        return ans;
    }
};
