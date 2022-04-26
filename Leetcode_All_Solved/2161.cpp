class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        int same_cnt = 0;
        for(const int& x:nums){
            if(x < pivot)less.push_back(x);
            else if(x > pivot)more.push_back(x);
            else same_cnt++;
        }
        vector<int> ans;
        ans.insert(ans.begin(), less.begin(), less.end());
        for(int i=0;i<same_cnt;i++)ans.push_back(pivot);
        ans.insert(ans.end(), more.begin(), more.end());
        return ans;
    }
};
