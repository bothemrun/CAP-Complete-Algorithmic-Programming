#include<assert.h>
class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            arr[i] = 2*i + 1;
            sum += arr[i];
        }

        assert(sum%n == 0);
        int target = sum / n;
        int cnt = 0;
        for(const int& x: arr){
            int d = x - target;
            if(d > 0) cnt += d;
        }
        return cnt;
    }
};
