class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> exp = heights;
        sort(exp.begin(), exp.end());

        int ans = 0;
        for(int i=0;i<exp.size();i++)
            ans += exp[i] != heights[i];
        return ans;
    }
};
