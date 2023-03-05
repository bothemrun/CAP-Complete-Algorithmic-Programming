#define notyet (-1)
#include<assert.h>
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(const string& s: words){
            bool permute = true;
            vector<int> biject1(26, notyet);
            vector<int> biject2(26, notyet);

            for(int i=0;i<pattern.size();i++){
                int c = s[i] - 'a';
                int p = pattern[i] - 'a';

                if(biject1[c] == notyet && biject2[p] == notyet ){
                    biject1[c] = p;
                    biject2[p] = c;
                }else if(biject1[c] == p ){
                    assert(biject2[p] == c );
                    continue;
                }else{
                    permute = false;
                    break;
                }
            }

            if(permute) ans.push_back(s);
        }

        return ans;
    }
};
