class Solution {
private:
    vector<int> ans = {-1, -1};
    void binary_transit_window(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            //NOTE:
            int begin = mid, end = mid;
            while(begin >= 0 && nums[begin] == target)begin--;
            begin++;
            while(end < nums.size() && nums[end] == target)end++;
            end--;
            
            ans[0] = begin, ans[1] = end;
            return;
        }//applies for low==high, 0, nums.size()-1
        if(low == high)return;
        
        if(nums[mid] < target)return binary_transit_window(nums, target, mid+1, high);
        else return binary_transit_window(nums, target, low, mid);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return ans;
        
        binary_transit_window(nums, target, 0, nums.size()-1);
        return ans;
    }
};
