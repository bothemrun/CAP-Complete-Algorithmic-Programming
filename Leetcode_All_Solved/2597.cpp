//NOTE: TLE with unordered_set, so use vector set
//actually Wrong answers for the AC codes of the weekly contest.
#define min_nums 1
#define max_nums 1000
class Solution {
public:
    vector<int> vset2cnt;
    int cnt = 0;
    
    inline int count(int x){
        if(!(min_nums<=x && x<=max_nums))
            return 0;
        return vset2cnt[x];
    }
    inline void insert(const int& x){
        vset2cnt[x]++;
    }
    inline void erase(const int& x){
        vset2cnt[x]--;
    }
    void subset_backtrack(const vector<int>& nums, const int& k, const int& i=0){
        if(i == nums.size()){
            cnt++;
            return;
        }

        subset_backtrack(nums, k, i+1);

        if(count(nums[i] + k) == 0 && count(nums[i] - k) == 0){
            insert(nums[i]);

            subset_backtrack(nums, k, i+1);

            erase(nums[i]);
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        vset2cnt = vector<int>(max_nums + 1, 0);
        subset_backtrack(nums, k);
        return cnt - 1;//non-empty
    }
};
