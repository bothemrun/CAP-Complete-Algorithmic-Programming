//m0
//O(sort) = O(nlogn)

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        int ans = 0;
        int sufsum = 0;//no overflow
        int coef = 0;//no overflow
        for(int i=n-1;i>=0;i--){
            sufsum += satisfaction[i];

            coef += sufsum;

            ans = max(ans, coef);
        }
        return ans;
    }
};
