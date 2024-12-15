//O(n/k * k) = O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n);
        pref.front() = nums.front();
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + (long long)nums[i];
        }
        assert(k-1 < n);
        long long ans = pref.at(k-1); //can't use 0
        
        for(int remainder=0;remainder<k;remainder++){
            long long min_prefix = 0; //can't use 0
            if(remainder-1 >= 0){
                min_prefix = pref.at(remainder-1);
            }
            
            for(int i=k-1 + remainder;i<n;i+=k){
                ans = max(ans, pref[i] - min_prefix);
                //update
                min_prefix = min(min_prefix, pref[i]);
            }
        }
        return ans;
    }
};
