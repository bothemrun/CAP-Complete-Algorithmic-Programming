//prefix hash.
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();

        const int max_nums = 201;
        //since it's strictlu increasing.
        bool has[max_nums] = {0};

        int cnt = 0;
        has[ nums[0] ] = true;
        has[ nums[1] ] = true;
        for(int i=2;i<n;i++){
            int x = nums[i] - diff;
            int y = nums[i] - 2*diff;

            if(x>=0 && y>=0 && has[x] && has[y] ) cnt++;

            has[ nums[i] ] = true;
        }

        return cnt;
    }
};
