#include<algorithm>
class Solution {
private:
    vector<int> ans;
    void binary(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){//also applies for size 1
            int left = mid;
            while(left-1 >= 0 && nums[left-1] == target)left--;
            int right = mid;
            while(right+1 < nums.size() && nums[right+1] == target)right++;
            for(int i=left;i<=right;i++)ans.push_back(i);
            return;
        }
        if(low == high)return;
        
        if(target < nums[mid])binary(nums, target, low, mid);
        else binary(nums, target, mid+1, high);
    }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        binary(nums, target, 0, nums.size()-1);
        return ans;
    }
};
