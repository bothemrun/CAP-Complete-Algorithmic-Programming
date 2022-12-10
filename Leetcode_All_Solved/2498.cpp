#include<algorithm>
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n <= 3)return stones.back() - stones[0];
        
        int max_len = max(stones[1] - stones[0], stones[2] - stones[0]);
        int i = 1, j = 2;
        while(i+2 < n && j+2 < n){
            //jump from i to i+2
            //printf("i %d %d j %d %d\n", i, i+2, j, j+2);
            max_len = max(max_len, stones[i+2] - stones[i]);
            max_len = max(max_len, stones[j+2] - stones[j]);
            i += 2;
            j += 2;
        }
        //cout << endl;
        if(i+2 == n-1) max_len = max(max_len, stones[n-1] - stones[n-3]);
        else max_len = max(max_len, stones[n-1] - stones[n-3]);
        return max_len;
    }
};
