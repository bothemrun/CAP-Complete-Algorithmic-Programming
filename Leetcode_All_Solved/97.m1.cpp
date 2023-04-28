//m1
//space optim bottom up dp.
//NOTE: fast init by array instead of vectors
#include<assert.h>
#include<string.h>
#define IDX(i) ((i)%2) //wrong: (i%2)
#define Memo(i) (memo[ IDX(i) ])
#define max_len 100

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())return false;

        bool memo[2][max_len+1] = {0};//NOTE: fast init by array
        Memo(0)[0] = true;
        //NOTE: all strings 0-indexed
        for(int j=1;j<=n;j++){
            if(s2[j-1] == s3[0+j-1]) Memo(0)[j] = true;
            else break;//already set false
        }

        for(int i=1;i<=m;i++){
            //NOTE: crucial
            memset( Memo(i), false, sizeof(Memo(i)) );

            assert(i-1>=0);
            Memo(i)[0] = Memo(i - 1)[0] && s1[i-1] == s3[i+0-1];

            for(int j=1;j<=n;j++){
                assert(j-1>=0);
                if(s1[i-1] == s3[i+j-1])
                    Memo(i)[j] |= Memo(i - 1)[j];
                if(s2[j-1] == s3[i+j-1])
                    Memo(i)[j] |= Memo(i)[j-1];
            }
        }

        return Memo(m)[n];
    }
};
