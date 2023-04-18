#include<algorithm>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int i=0, j=0;
        string ans = "";
        for(int k=0;k<min(m,n);k++){
            //NOTE: wrong due to char addtion
            //ans += word1[i++] + word1[j++];
            ans += word1[i++];
            ans += word2[j++];
        }

        if(m>n) ans += word1.substr(i);
        else if(m<n) ans += word2.substr(j);
        return ans;
    }
};
