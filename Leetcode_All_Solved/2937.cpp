#include<algorithm>
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        int minlen = min( {a, b, c} );
        int i;
        for(i=0;i<minlen;i++){
            if( s1[i] != s2[i] || s1[i] != s3[i] || s2[i] != s3[i] ){
                break;
            }
        }
        
        if(i==0) return (-1);
        return a+b+c - 3*i;
    }
};
