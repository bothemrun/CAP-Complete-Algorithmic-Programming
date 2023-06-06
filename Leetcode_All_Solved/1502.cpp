#define offset ((int)1e6)
#define memo_size (offset*2+1)
#include<algorithm>
/*#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        bool vset[memo_size] = {0};
        for(const int& x: arr) vset[offset+x] = true;
        
        int mi = *min_element(arr.begin(), arr.end());
        int ma = *max_element(arr.begin(), arr.end());
        //NOTE: edge case: all the same
        if(mi == ma) return true;

        int n = arr.size();
        if((ma - mi)%(n-1) != 0) return false;
        int diff = (ma - mi)/(n-1);

        for(int i=0;i<n;i++){
            if(!vset[offset+mi + i*diff]) return false;
        }
        return true;
    }
};
