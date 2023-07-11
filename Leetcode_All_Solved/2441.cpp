#include<stdlib.h>
#include<algorithm>
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        const int offset = 1000;
        const int memo_size = 2*offset + 1;
        bool memo[memo_size] = {0};

        int max_pos = (-1);
        for(const int& x: nums){
            if(memo[offset - x] == true)
                max_pos = max(max_pos, abs(x) );
            
            memo[offset + x] = true;
        }

        return max_pos;
    }
};
