#include<limits.h>
class Solution {
public:
    int n;
    const long long no_last = LLONG_MAX;

    bool backtrack(const string& s, const int& i, const long long& last, const int& part){
        if(i==n){
            return (part>=2)? true:false;
        }

        bool ret = false;
        //[i, j] 1 partition
        long long cur = 0;
        for(int j=i;j<n;j++){
            //long long overflow pruning
            //LLONG_MAX = 9e18
            if(cur >= 1e11) break;

            cur = cur*10LL + stoll( s.substr(j, 1) );

            if(last==no_last || last-1==cur)
                ret |= backtrack(s, j+1, cur, part+1);
            
            //prune
            if(ret==true) return ret;
        }

        return false;
    }

    bool splitString(string s) {
        n = s.size();

        return backtrack(s, 0, no_last, 0);
    }
};
