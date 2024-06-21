#define pari(x) (x%2==0)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i+1<n;i++){
            if( pari(nums[i]) == pari(nums[i+1]) ) return false;
        }
        return true;
    }
};
