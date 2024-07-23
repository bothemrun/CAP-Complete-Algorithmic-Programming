//m1

//[A] 3 pass: prefix & suffix LIS

//[B] LIS by tree array & binary search in O(nlogn)

//a. 1964	Find the Longest Valid Obstacle Course at Each Position	hard
//b. 300	Longest Increasing Subsequence	medium.

//O(nlogn)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline void LIS_tree_arr(const vector<int>& nums, vector<int>& lis){
        vector<int> tree_arr;

        for(int i=0;i<n;i++){
            //strictly increasing --> lower_bound
            auto it = lower_bound(
                tree_arr.begin(),
                tree_arr.end(),
                nums[i]
            );

            //if empty, v.begin() == v.end()
            if(it == tree_arr.end()){
                tree_arr.push_back(nums[i]);

                lis[i] = tree_arr.size();
            }else{
                lis[i] = ( it - tree_arr.begin() ) - (0-1);

                //the replacement is crucial
                *it = nums[i];
            }
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        this->n = nums.size();

        vector<int> pre_lis(n);
        LIS_tree_arr(nums, pre_lis);

        reverse(nums.begin(), nums.end());
        vector<int> suf_lis(n);
        LIS_tree_arr(nums, suf_lis);

        int max_mountain = 3;//testcases guaranteed to have a mountain
        for(int i=1;i+1<n;i++)if(pre_lis[i] >= 2 && suf_lis[ (n-1) - i ] >= 2){
            max_mountain = max(
                max_mountain,
                pre_lis[i] + suf_lis[ (n-1) - i ] - 1
            );
        }
        return n - max_mountain;
    }
};
