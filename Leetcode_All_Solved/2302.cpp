class Solution {
public:
    inline int window_size(const int& window_low, const int& i){
        //0 if window_low == i+1
        return i - (window_low - 1);
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0;
        int window_low = 0;
        long long window_sum = 0;
        for(int i=0;i<n;i++){
            window_sum += nums[i];
            while(window_low <= i && !(window_size(window_low, i) * window_sum < k) )
                window_sum -= nums[window_low++];
            cnt += window_size(window_low, i);
        }
        return cnt;
    }
};
