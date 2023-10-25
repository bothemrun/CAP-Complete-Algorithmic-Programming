//naive for loop causes overflow
//boolean not "!" can't use flip "~" --> turned into int,
//~false turned into int (-1)
#include<assert.h>

class Solution {
public:
    bool triangle(const int& n, const int& k){
        if(n==1){
            assert(k==1);
            return false;
        }

        bool parent = triangle(n-1, (k+1)/2);
        //boolean not "!" can't use flip "~" --> turned into int,
        //~false turned into int (-1)
        return (!parent) ^ (k%2);
    }
    int kthGrammar(int n, int k) {
        return triangle(n, k);
    }
};
