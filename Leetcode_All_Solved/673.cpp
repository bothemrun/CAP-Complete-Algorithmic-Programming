#include<limits.h>
class ss{
public:
    int lis;
    int same_cnt;
    ss(const int& lis_, const int& same_cnt_){
        lis = lis_;
        same_cnt = same_cnt_;
    }
    //ss(){}
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<class ss> dp_ending(n, ss(1, 1) );

        //NOTE: init for len 1
        int max_lis = 1; //NOTE: INT_MIN;
        int max_lis_cnt = 1; //NOTE: INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp_ending[i].lis < dp_ending[j].lis + 1)
                        dp_ending[i] = ss( dp_ending[j].lis + 1, dp_ending[j].same_cnt); //1 );
                    else if(dp_ending[i].lis == dp_ending[j].lis + 1){
                        //NOTE: not dp_ending[i].same_cnt++;
                        dp_ending[i].same_cnt += dp_ending[j].same_cnt;
                    }
                }//else already init
            }


            if(dp_ending[i].lis > max_lis){
                max_lis = dp_ending[i].lis;
                max_lis_cnt = dp_ending[i].same_cnt;
            }else if(dp_ending[i].lis == max_lis)
                max_lis_cnt += dp_ending[i].same_cnt;
        }

        return max_lis_cnt;
    }
};
