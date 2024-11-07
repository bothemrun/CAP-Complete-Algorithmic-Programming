class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> seg_max;
        int i=0;
        while(i<n){
            int mi = nums[i];
            int ma = nums[i];

            int j=i;
            //while(j+1<n && popcount(nums[j+1]) == popcount(nums[i])){
            while(j+1<n && __builtin_popcount(nums[j+1]) == __builtin_popcount(nums[i])){
                j++;
                mi = min(mi, nums[j]);
                ma = max(ma, nums[j]);
            }

            //check
            if(seg_max.size() && seg_max.back() > mi)
                return false;
            
            seg_max.push_back(ma);

            //update
            i = j+1;
        }
        return true;
    }
};
