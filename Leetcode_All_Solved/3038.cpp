class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 1;
        int val = nums[0] + nums[1];//n>=2
        for(int i=2;i+1<n;i+=2){
            if(nums[i] + nums[i+1] == val) op++;
            else break;
        }
        return op;
    }
};