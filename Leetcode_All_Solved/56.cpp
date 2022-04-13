#include<algorithm>
inline bool cmp_left(const vector<int>& interval1, const vector<int>& interval2){
    return interval1[0] < interval2[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp_left);
        
        int n = intervals.size();
        vector<vector<int>> merged;
        int left_idx = 0;
        int left, right;
        while(left_idx < n){
            left = intervals[left_idx][0];
            right = intervals[left_idx][1];
            while(left_idx + 1 < n && intervals[left_idx+1][0] <= right){
                left_idx++;
                //right = intervals[left_idx][1];
                right = max(right, intervals[left_idx][1]);
            }
            
            merged.push_back( vector<int>({left, right}) );
            left_idx++;
        }
        return merged;
    }
};
