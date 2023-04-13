//greedy construction
#include<assert.h>
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low=0, high=n;
        vector<int> di(n+1);
        
        if(s[0] == 'I') di[0] = low++;
        else di[0] = high--;

        for(int i=1;i<=n;i++){
            if(s[i-1] == 'I'){
                if(s[i] == 'I') di[i] = low++;
                else di[i] = high--;
            }else{//s[i-1] = 'D
                if(s[i] == 'I') di[i] = low++;
                else di[i] = high--;
            }

            assert(i==n || low<=high);
        }
        return di;
    }
};
