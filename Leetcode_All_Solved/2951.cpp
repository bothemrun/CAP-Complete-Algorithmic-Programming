class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector<int> ans;
        for(int i=1;i+1<n;i++)if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1] )
            ans.push_back(i);
        return ans;
    }
};
