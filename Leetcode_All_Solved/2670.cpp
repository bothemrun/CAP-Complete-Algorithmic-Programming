#include<unordered_set>
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> pset;
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            pset.insert(nums[i]);
            prefix[i] = pset.size();
        }
        
        unordered_set<int> sset;
        vector<int> suffix(n);
        suffix[n-1] = 0;
        for(int i=n-1-1;i>=0;i--){
            sset.insert(nums[i+1]);
            suffix[i] = sset.size();
        }
        
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i] = prefix[i] - suffix[i];
        }
        return diff;
    }
};
