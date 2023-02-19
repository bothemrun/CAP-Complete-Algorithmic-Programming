#define max_a ((int)1e5)
#include<limits.h>
#include<algorithm>
class Solution {
public:
    inline int cnt1(int x){
        int cnt = 0;
        while(x > 0){
            cnt += x%2;
            x /= 2;
        }
        return cnt;
    }
    int minOperations(int n) {
        int min_op = INT_MAX;
        for(int a=0;a<=max_a;a++){
            min_op = min(min_op, cnt1(a) + cnt1(n+a) );
        }
        return min_op;
    }
};
