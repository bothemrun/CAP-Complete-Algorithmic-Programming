//O(n * log qn)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int qn;
    int n;
    inline bool good(const vector<int>& nums, const vector<vector<int>>& queries, const int k){
        //edge case
        if(k == (-1)) return false;
        assert(0<=k && k<=qn);

        vector<int> diff(n+1, 0);
        for(int qi=0;qi < min(k, qn);qi++){
            diff[ queries[qi][0] ] -= queries[qi][2];
            diff[ queries[qi][1] + 1 ] += queries[qi][2];
        }

        int sweep = 0;//no overflow
        for(int pos=0;pos<n;pos++){
            sweep += diff[pos];

            if(nums[pos] + sweep > 0) return false;
        }
        return true;
    }
    int binary(const vector<int>& nums, const vector<vector<int>>& queries, int low, int high){
        int mid = low + (high-low)/2;
        bool mid_res = good(nums, queries, mid);
        if(mid_res==true && good(nums, queries, mid-1)==false)
            return mid;
        
        if(low == high) return (-1);

        if(mid_res==true)
            return binary(nums, queries, low, mid);
        else
            return binary(nums, queries, mid+1, high);
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->qn = queries.size();
        
        return binary(nums, queries, 0, qn);
    }
};
