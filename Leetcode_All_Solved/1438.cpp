//m0

//O(nlogn) sliding window + tree set (multiset)
//logic might be better

#include<set>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int ans = 0;

        multiset<int> ms;

        int win_min = INT_MAX;
        int win_max = INT_MIN;

        //[i, j] window
        int j = (-1);

        for(int i=0;i<n;i++){
            j = max(j, i-1);
            while(
                j+1<n &&
                max(win_max, nums[j+1]) - min(win_min, nums[j+1]) <= limit
            ){
                ms.insert(nums[++j]);

                win_max = max(win_max, nums[j]);
                win_min = min(win_min, nums[j]);
            }

            ans = max(ans, j - (i-1) );

            //update, drop
            assert( ms.find(nums[i]) != ms.end() );

            //ms.erase(val) --> erase all instances of val
            //ms.erase(ms.find(val)) --> erase 1 instance
            ms.erase( ms.find(nums[i]) );

            if(win_min == nums[i]){
                if(ms.size() == 0){
                    assert(i==j);
                    win_min = INT_MAX;
                }else{
                    win_min = *(ms.begin());
                }
            }

            if(win_max == nums[i]){
                if(ms.size() == 0){
                    assert(i==j);
                    win_max = INT_MIN;
                }else{
                    win_max = *(ms.rbegin());
                }
            }
        }

        return ans;
    }
};
