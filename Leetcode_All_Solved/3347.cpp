//m0

//it's like a "Three Pointer" method.
//why O(nlogn)? 'cuz left & right are monotonically non-decreasing during the main loop for mid.

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        //XXX: start of I 3346. but modified
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        unordered_map<int,int> ma;
        for(const int& x: nums) ma[x]++;
        
        int ans = 0;
        const int max_nums = (int)1e5;
        for(const int& x: nums){
        //for(int x=0;x<=max_nums+2;x++){
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
        //XXX: end of I 3346.
        

        //XXX: new for II 3347.
        for(int mid_i=0;mid_i<n-1;mid_i++){
            int mid = nums.at(mid_i);
            int left = mid - k;
            int right = mid + k;
            
            while(true){
                int left_i = lower_bound(nums.begin(), nums.end(), left) - nums.begin();
                if(left_i >= n){
                    break;
                }
                int right_i = ( upper_bound(nums.begin(), nums.end(), right) - nums.begin() ) - 1;
                if(!(right_i >= 0)){
                    break;
                }
                int candidate = min(right_i - (left_i-1), numOperations);
                /*if(se.find(mid) != se.end()){
                    //candidate = min(right - (left-1), numOperations + 1);
                    candidate = min(right_i - (left_i-1), numOperations + ma[mid]);
                }else{
                    candidate = min(right_i - (left_i-1), numOperations);
                }*/
                ans = max(ans, candidate);
                
                //update for next
                int left_next_i = upper_bound(nums.begin(), nums.end(), left) - nums.begin();
                if(left_next_i > mid_i){
                    break;
                }
                int right_next_i = upper_bound(nums.begin(), nums.end(), right) - nums.begin();
                if(right_next_i >= n){
                    break;//only decreases
                }
            
                int delta = min( nums.at(left_next_i) - left, nums.at(right_next_i) - right );
                //update
                left += delta;
                right += delta;
                if(nums.at(mid_i + 1) <= left + k){
                    break;
                }
            }//end while
        }
        return ans;
    }
};
