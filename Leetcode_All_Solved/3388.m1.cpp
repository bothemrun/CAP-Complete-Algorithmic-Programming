//m1
//2 rolling hash to prevent collision

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    void get_roll(const vector<int>& nums, vector<vector<int>>& roll, const long long mod, const long long p, const long long initial){
        roll.resize(n, vector<int>(n));
        for(int i=0;i<n;i++){
            long long hash = initial;
            for(int j=i;j<n;j++){
                hash *= (long long)p;
                hash += (long long)nums[j] + 3LL;
                hash %= mod;

                roll[i][j] = hash;
            }
        }
    }
    int beautifulSplits(vector<int>& nums) {
        this->n = nums.size();
        vector<vector<int>> roll1;
        get_roll(nums, roll1, (long long)1e7 + 19LL, 37LL, 103LL);
        vector<vector<int>> roll2;
        get_roll(nums, roll2, (long long)1e9 + 7LL, 41LL, 107LL);
        
        auto check = [n = this->n](const vector<vector<int>>& roll, const int i, const int j){
            int end2 = (i+1) + i;
            if(end2<=j){
                if(roll[0][i] == roll[i+1][end2]){
                    return true;
                }
            }
            int end3 = j+1 + (j - (i+1));
            if(end3<n){
                if(roll[i+1][j] == roll[j+1][end3]){
                    return true;
                }
            }
            return false;
        };

        long long ans = 0;
        for(int i=0;i<n;i++){
            //nums1 [0, i]
            for(int j=i+1;j+1<n;j++){
                //nums2 [i+1, j]
                //nums3 [j+1, n-1]
                assert(i+1<n);
                assert(j+1<n);
                bool good = check(roll1, i, j) && check(roll2, i, j);
                //bool good = check(roll2, i, j);
                ans += good;
            }
        }
        return ans;
    }
};
