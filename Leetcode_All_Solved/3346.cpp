//m0
//O(max_nums * log n)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        unordered_map<int,int> ma;
        for(const int& x: nums) ma[x]++;
        
        int ans = 0;
        const int max_nums = (int)1e5;
        //for(const int& x: nums){
        for(int x=0;x<=max_nums+2;x++){
            auto left_it = lower_bound(nums.begin(), nums.end(), x-k);
            auto right_it = upper_bound(nums.begin(), nums.end(), x+k);
            
            //assert(left_it != nums.end());
            if(left_it == nums.end()){
                continue;
            }
            int left = left_it - nums.begin();
            
            int right = ( right_it - nums.begin() ) - 1;
            //assert(right>=0);
            if(!(right>=0)){
                continue;
            }
            
            int candidate;
            if(ma[x] != 0){
                //candidate = min(right - (left-1), numOperations + 1);
                candidate = min(right - (left-1), numOperations + ma[x]);
            }else{
                candidate = min(right - (left-1), numOperations);
            }
            ans = max(ans, candidate);
        }
        
        return ans;
    }
};
