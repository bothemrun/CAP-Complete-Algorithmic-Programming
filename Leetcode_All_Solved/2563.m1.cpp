//m1
//O(nlogn) two pointers
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline long long count(const vector<int>& nums, const int bound){
        long long ret = 0;

        int bad_right = n;//[i+1, bad_right)
        for(int i=0;i<n;i++){
            while(bad_right>=i+2 && !(nums[i] + nums[bad_right-1] <= bound) ){
                bad_right--;
            }

            if(!(i+2 <= bad_right)) break;

            ret += (bad_right-1) - i;
        }
        return ret;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        this->n = nums.size();
        sort(nums.begin(), nums.end());

        return count(nums, upper) - count(nums, lower-1);
    }
};
