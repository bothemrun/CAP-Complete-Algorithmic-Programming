class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int thresh = k * threshold;
        int ans = 0;
        
        int cur_sum = 0;
        for(int i=0;i<k;i++)cur_sum += arr[i];
        if(cur_sum >= thresh)ans++;
        
        for(int i=k;i<arr.size();i++)if( (cur_sum = cur_sum + arr[i] - arr[i-k]) >= thresh )ans++;
        return ans;
    }
};
