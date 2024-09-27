//m1
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline int missing_cnt(const vector<int>& nums, const int i){
        if(i>=n) return INT_MAX;
        return nums[i]-1 - nums[0] - ( (i-1) - 0 );
    }
    int binary(const vector<int>& nums, int low, int high, const int& k){
        int mid = low + (high-low)/2;
        int mid_missing = missing_cnt(nums, mid);
        if(mid_missing < k && k <= missing_cnt(nums, mid+1) ){
            return nums[mid] + (k - mid_missing);
        }
        
        if(mid_missing < k)
            return binary(nums, mid+1, high, k);
        else
            return binary(nums, low, mid, k);
    }
    int missingElement(vector<int>& nums, int k) {
        n = nums.size();
        return binary(nums, 0, n-1, k);
    }
};