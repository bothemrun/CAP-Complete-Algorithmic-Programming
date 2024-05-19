class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int mi = INT_MAX;
        for(const int& x: nums){
            uset.insert(x);
            mi = min(mi, x);
        }

        int n = nums.size();
        for(int x=mi;x<=mi + n-1;x++)if(uset.count(x) == 0) return false;
        return true;
    }
};
