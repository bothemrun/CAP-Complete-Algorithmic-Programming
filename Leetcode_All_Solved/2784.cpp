class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = (int)nums.size() - 1;

        const int max_num = 201;
        int has[max_num] = {0};
        for(const int& x: nums){
            if(!(1<=x && x<=n)) return false;

            if(x == n){
                if(++has[x] == 3) return false;
            }else if(has[x]){
                return false;
            }else{
                has[x] = true;
            }
        }

        return true;
    }
};
