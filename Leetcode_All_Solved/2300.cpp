#include<algorithm>
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            //NOTE: overflow:int potion = success / spells[i];
            long long potion = success / (long long)spells[i];
            //to find the cases of success%spell == 0, O(logm) is better than O(m)
            if(success % spells[i] == 0)
                ans[i] = m - ( lower_bound(potions.begin(), potions.end(), potion) - potions.begin() );
            else
                ans[i] = m - ( upper_bound(potions.begin(), potions.end(), potion) - potions.begin() );
        }
        return ans;
    }
};
