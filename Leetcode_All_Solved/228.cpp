class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int start = i;
            while(i+1<n && nums[i]+1==nums[i+1]) i++;
            //[start, i] is consecutive

            if(start == i) ans.push_back( to_string(nums[i]) );
            else ans.push_back( to_string(nums[start]) + "->" + to_string(nums[i]) );

            //next
            i++;
        }

        return ans;
    }
};
