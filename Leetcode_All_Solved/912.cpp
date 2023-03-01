class Solution {
public:
    void divide_conquer(const vector<int>& nums, const int& low, const int& high, vector<int>& res){
        if(low == high){
            res.push_back(nums[low]);
            return;
        }
        int mid = (high-low)/2 + low;
        vector<int> res_l, res_r;
        divide_conquer(nums, low, mid, res_l);
        divide_conquer(nums, mid+1, high, res_r);

        int i=0, j=0, m=res_l.size(), n=res_r.size();
        while(i<m && j<n){
            if(res_l[i] <= res_r[j])
                res.push_back(res_l[i++]);
            else res.push_back(res_r[j++]);
        }

        while(i<m)
            res.push_back(res_l[i++]);
        while(j<n)
            res.push_back(res_r[j++]);
    }
    vector<int> sortArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> res;
       divide_conquer(nums, 0, n-1, res);
       return res;
    }
};
