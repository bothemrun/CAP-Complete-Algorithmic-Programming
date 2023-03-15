#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<double> s;
        int i = 0, j = n-1;
        while(i < j){
            s.insert( ( (double)nums[i++] + (double)nums[j--] )/2 );
        }
        return s.size();
    }
};
