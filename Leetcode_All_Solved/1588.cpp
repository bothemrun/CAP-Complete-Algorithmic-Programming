class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix_sum = {0};
        for(const int& a:arr)prefix_sum.push_back(prefix_sum.back() + a);
        
        int sum = 0;
        for(int high=1;high<prefix_sum.size();high+=2)sum += prefix_sum[high];
        for(int low=2;low<prefix_sum.size();low++){
            for(int high=low;high<prefix_sum.size();high+=2)
                sum += prefix_sum[high] - prefix_sum[low-1];
        }
        return sum;
    }
};
