//m1
//space optim bottom up dp
//NOTE: for i==0, just set both sum(skip or not) to be arr[0]
#define IDX(i) ((i%3 + 3)%3)
#define Memo(i) (memo[ IDX(i) ])
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int memo[3][2] = {0};

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            Memo(i)[0] = max( arr[i], arr[i] + Memo(i-1)[0] );
            //NOTE: not check i-2>=0, so also include the element itself alone.
            Memo(i)[1] = max(
                arr[i] + Memo(i-1)[1],
                arr[i] + Memo(i-2)[0]
            );

            ans = max({ans, Memo(i)[0], Memo(i)[1] });
        }
        return ans;
    }
};
