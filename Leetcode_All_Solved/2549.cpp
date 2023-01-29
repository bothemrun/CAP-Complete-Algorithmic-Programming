#define maxd ((int)(1e9))
#include<unordered_set>
class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> s;
        s.insert(n);
        for(int d=0;d<maxd;d++){
            unordered_set<int> new_s;
            for(auto x: s){
                for(int i=2;i<=n;i++)if(x%i == 1 && s.count(i) == 0)
                    new_s.insert(i);
            }
            
            if(new_s.size() == 0)break;
            s.insert(new_s.begin(), new_s.end());
        }
        return (int)s.size();
    }
};
