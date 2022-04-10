class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum = {nums[0]};
        for(int i=1;i<n;i++)prefix_sum.push_back(prefix_sum.back() + nums[i]);
        
        for(int mid=0;mid<n;mid++){
            if(mid==0){
                if(0 == prefix_sum.back() - prefix_sum[mid])return 0;
            }else if(mid==n-1){
                if(prefix_sum[mid-1] == 0)return n-1;
            }else if(prefix_sum[mid-1] == prefix_sum.back() - prefix_sum[mid])return mid;
        }
        return (-1);
    }
};
