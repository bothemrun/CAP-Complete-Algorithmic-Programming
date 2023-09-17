//O(n)

#include<assert.h>

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int r_sum = 0;
        int r_cnt = 0;
        for(int i=1;i<n;i++)if(boxes[i] == '1'){
            r_cnt++;
            r_sum += i;
        }

        vector<int> ans(n);
        ans[0] = r_sum;

        int l_sum = 0;
        int l_cnt = 0;
        for(int i=1;i<n;i++){
            r_sum -= r_cnt;
            assert(r_sum >= 0);

            if(boxes[i] == '1') r_cnt--;
            assert(r_cnt >= 0);

            if(boxes[i-1] == '1') l_cnt++;
            l_sum += l_cnt;


            ans[i] = l_sum + r_sum;
        }

        return ans;
    }
};
