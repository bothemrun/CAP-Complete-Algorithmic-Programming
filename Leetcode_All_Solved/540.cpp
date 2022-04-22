class Solution {
private:
    inline bool good(const vector<int>& nums, int i){
        return nums.at(2*i) == nums.at(2*i+1);
    }
    int binary_see2(const vector<int>& nums, int low, int high){
        //even size
        int mid = low + (high-low)/2;
        if(mid == 0 && !good(nums,mid) )return nums.at(2*mid);
        if(mid != 0 && good(nums, mid-1) && !good(nums,mid))return nums.at(2*mid);
        if(low == high)return (-3);//not here
        
        if(good(nums,mid))return binary_see2(nums, mid+1, high);
        else return binary_see2(nums, low, mid);
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() ==1 || nums[nums.size()-1] != nums[nums.size()-2])return nums.back();
        return binary_see2(nums, 0, (nums.size()-1-2)/2 );
    }
};
