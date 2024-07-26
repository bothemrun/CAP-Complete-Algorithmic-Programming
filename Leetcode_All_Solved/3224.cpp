//m0
//O(n + k) = 1e5 difference array
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();

        //difference array for diff to operations
        //max diff = k
        vector<int> diff(k+1 + 1, 0);//extra +1 for -1

        for(int i=0;i<n/2;i++){
            const int di = abs( nums[i] - nums[n-1 - i] );

            diff[di]--;
            diff[di+1]++;

            //int min_diff2op = min( k - mi, ma - 0 ) + 1;
            int max_diff2op = max(
                k - min(nums[i], nums[n-1 - i]),
                max(nums[i], nums[n-1 - i]) - 0
            ) + 1;
            
            diff[max_diff2op]++;
        }

        int ans = INT_MAX;
        int sweep = n/2; //base is n/2
        for(const int& delta: diff){
            sweep += delta;

            ans = min(ans, sweep);
        }
        return ans;
    }
};
