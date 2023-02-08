#include<assert.h>
class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int cnt1group = 0;
        
        int low = 0;
        while(low < n){
            while(low < n && target[low] == '0'){
                low++;
            }
            //NOTE: necessary: if no 1s
            if(!(low < n))break;

            //NOTE: [low, high)
            int high = low;
            while(high < n && target[high] == '1'){
                high++;
            }

            assert(target[low] == '1');
            cnt1group++;

            low = high + 1;
        }

        //NOTE: edge case
        if(target.back() == '1')
            return cnt1group*2 - 1;
        else return cnt1group*2;
    }
};
