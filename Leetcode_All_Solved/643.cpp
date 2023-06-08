class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<k;i++)
            sum += nums.at(i);
        int max_sum = sum;
        for(int i=k;i<nums.size();i++){
            sum -= nums.at(i-k);
            sum += nums.at(i);
            if(sum > max_sum)
                max_sum = sum;
        }
        return (double)max_sum / (double)k;
    }
};
