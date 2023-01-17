#include<algorithm>
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m, true);

        for(int i=0;i<m;i++){
            int len = r[i] - (l[i] - 1);
            vector<int> sub( len );
            for(int j=l[i];j<=r[i];j++)
                sub[ j-l[i] ] = nums[j];
            
            sort(sub.begin(), sub.end());

            for(int j=2;j<len;j++){
                if(sub[j] - sub[j-1] != sub[j-1] - sub[j-2]){
                    ans[i] = false;
                    break;
                }
            }
        }
        
        return ans;
    }
};
