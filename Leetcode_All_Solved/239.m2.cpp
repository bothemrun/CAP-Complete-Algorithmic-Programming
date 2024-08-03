//m2
//ordered set
//O(nlogn)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        multiset<int> ms;
        for(int i=0;i<k-1;i++){
            ms.insert(nums[i]);
        }

        for(int i=k-1;i<n;i++){
            //update, add
            ms.insert(nums[i]);
            //update, drop
            //erase(val) erases all instances
            if(i-k >= 0) ms.erase( ms.find(nums[i-k]) );

            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};
