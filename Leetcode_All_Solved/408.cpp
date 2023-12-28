#include<ctype.h>

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size();
        int n = abbr.size();

        int i=0, j=0;
        while(j<n){
            if(isdigit( abbr[j] )){
                int start = j;
                while(j+1<n && isdigit( abbr[j+1] ) ){
                    j++;
                }
                int end = j;


                int len = end - (start-1);
                string sub = abbr.substr(start, len);
                //NOTE: edge: leading 0 or replacing an empty substring
                if(sub.front() == '0') return false;

                int skip = stoi(sub);

                if(i + (skip-1) >= m) return false;
                i += skip;

                //update
                j++;
            }else{
                if(!(i<m)) return false;
                if(word[i] != abbr[j]) return false;

                //update
                i++;
                j++;
            }
        }

        return i==m;
    }
};
