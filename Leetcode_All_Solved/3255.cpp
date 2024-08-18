//m0
//O(n) sliding window
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - (k-1));

        //make the 1st window
        int last_good = 0; //edge case: k==1
        for(int i=1;i<k-1;i++){
            if(!( nums[i-1] + 1 == nums[i] )){
                last_good = i;
            }
        }

        for(int j=k-1;j<n;j++){
            if(j-1 >= 0){
                if(!( nums[j-1] + 1 == nums[j] )){
                    last_good = j;
                }
            }

            //crucial
            last_good = max(last_good, j - (k-1));

            ans[j - (k-1)] = (last_good == j - (k-1) )? nums[j]:(-1);
        }
        return ans;
    }
};
