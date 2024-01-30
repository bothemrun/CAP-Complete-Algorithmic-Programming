//O(n) 1 pass

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        
        //last key covers [..., last_right]
        int last_right = (-1);
        for(int i=0;i<n;i++)if(nums[i] == key){
            //this key covers [left, right]
            int right = min(n-1, i+k);
            int left = max(0, i-k);

            if(last_right >= left){
                for(int j=last_right+1;j<=right;j++)
                    ans.push_back(j);
            }else{
                for(int j=left;j<=right;j++)
                    ans.push_back(j);
            }

            last_right = right;
        }

        return ans;
    }
};
