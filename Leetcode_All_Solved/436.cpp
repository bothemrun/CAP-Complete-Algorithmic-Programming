#include<algorithm>
class Solution {
private:
    vector<vector<int>> intervals_idx;
    int n;
    static bool cmp_ptr(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }
    int binary(const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(mid == 0 && intervals_idx[0][0] >= target)return intervals_idx[0][2];
        if(mid != 0 && intervals_idx[mid][0] >= target && intervals_idx[mid-1][0] < target)return intervals_idx[mid][2];
        if(low == high)return (-1);
        
        if(intervals_idx[mid][0] < target)return binary(target, mid+1, high);
        else return binary(target, low, mid);
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        n = intervals.size();
        intervals_idx = vector<vector<int>>(n, vector<int>(3));
        for(int i=0;i<n;i++) intervals_idx[i] = {intervals[i][0], intervals[i][1], i};
        sort(intervals_idx.begin(), intervals_idx.end(), cmp_ptr);
        
        vector<int> ans;
        for(int i=0;i<n;i++)ans.push_back( binary(intervals[i][1], 0, n-1) );
        return ans;
    }
};
