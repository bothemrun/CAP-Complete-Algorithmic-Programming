#define max_n (int)1e5
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        bool vset[max_n + 1] = {0};
        for(const int& x: nums) vset[x] = true;
        
        vector<int> ans;
        for(int x=1;x<=n;x++)if(vset[x] == false) ans.push_back(x);
        return ans;
    }
};
