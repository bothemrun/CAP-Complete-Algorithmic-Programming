//O(nlogn)
//the key is the jump table (DP).

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> jump;
    int n;
    inline bool good(const vector<int>& nums, const int k){
        for(int a=0;a<n;a++){
            int b = a + k;
            if(!(b<n)){
                return false;
            }
            int end2 = b+k-1;
            if(!(end2 < n)){
                return false;
            }
            
            if(!( jump[a] >= b-1 )){
                continue;
            }
            if(!( jump[b] >= end2 )){
                continue;
            }
            return true;
        }
        return false;
    }
    int binary(const vector<int>& nums, int low, int high){
        int mid = (high-low)/2 + low;
        bool mid_res = good(nums, mid);
        if(mid_res==true && good(nums, mid+1)==false){
            return mid;
        }
        
        if(mid_res==true) return binary(nums, mid+1, high);
        else return binary(nums, low, mid);
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        this->n = nums.size();
        jump.resize(n);
        jump.back() = n-1;
        for(int i=n-2;i>=0;i--){
            if( nums[i] < nums[i+1] ){
                jump[i] = jump[i+1];
            }else{
                jump[i] = i;
            }
        }
        return binary(nums, 1, n/2+2);
    }
};
