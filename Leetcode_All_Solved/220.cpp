//m0
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
    multiset<int> ms;
    inline bool binary_range(const int low, const int high){
        if(ms.size() == 0) return false;
        //the hard part is that multiset iterators are not random iterators,
        auto it = ms.lower_bound(low);
        return it != ms.end() && *it <= high;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        this->n = nums.size();
        for(int i=0;i<n;i++){
            /*
            abs(x-y) <= diff:
            (1) if x<y:
            y-x <= diff
            y-diff <= x
            --> (y-diff) <= x < y
            --> (y-diff) <= x <= y-1

            (2) if x>=y:
            x <= y+diff
            --> y <= x <= (y+diff)
            */
            if(
                binary_range(nums[i] - valueDiff, nums[i] - 1) ||
                binary_range(nums[i], nums[i] + valueDiff)
            ) return true;


            //update, add
            ms.insert(nums[i]);
            
            //update drop
            int left = i - indexDiff;
            if(left>=0){
                //ms.erase(val) erases all instances of val
                ms.erase( ms.find(nums[left]) );
            }
        }
        return false;
    }
};
