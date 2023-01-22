//m1
#include<assert.h>
class Solution {
public:
    int minOperations(int n) {
        int sum = ((n-1))*((n-1) + 1) + n;
        
        assert(sum%n == 0);
        int target = sum / n;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int d = (2*i + 1) - target;
            if(d > 0) cnt += d;
        }
        return cnt;
    }
};
