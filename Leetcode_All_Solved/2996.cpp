class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int seq;
        for(seq=0;seq+1<n;seq++){
            sum += nums[seq];

            if(nums[seq] != nums[seq+1] - 1){
                break;
            }
        }


        if(seq == n-1) sum += nums.back();

        const int max_nums = 50 + 1;
        bool has[max_nums] = {0};
        for(int i=seq;i<n;i++) has[ nums[i] ] = true;

        int x = sum;
        while(x < max_nums && has[x] == true) x++;
        return x;
    }
};
