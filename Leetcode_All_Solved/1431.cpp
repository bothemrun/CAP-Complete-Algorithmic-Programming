#include<algorithm>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> res(n);
        for(int i=0;i<n;i++)
            res[i] = candies[i] + extraCandies >= max_candy;
        return res;
    }
};
