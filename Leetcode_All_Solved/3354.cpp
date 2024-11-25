class Solution {
public:
    int n;
    int ans = 0;
    inline void brute(vector<int> nums, int cur, int delta){
        while(0<=cur && cur<n){
            if(nums[cur] == 0){
                cur += delta;
            }else if(nums[cur] > 0){
                nums[cur]--;
                delta *= (-1);
                cur += delta;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                return;
            }
        }
        ans++;
    }
    int countValidSelections(vector<int>& nums) {
        this->n = nums.size();
        for(int i=0;i<n;i++)if(nums[i] == 0){
            brute(nums, i, 1);
            brute(nums, i, -1);
        }
        return ans;
    }
};
