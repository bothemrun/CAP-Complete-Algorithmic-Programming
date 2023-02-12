#include<string>
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int half = n/2;
        for(int i=0;i<half;i++){
            sum += stoi( to_string(nums[i]) + to_string(nums[n-1 - i]) );
        }
        
        if(n%2 == 1)
            sum += stoi( to_string(nums[n/2]) );
        return sum;
    }
};
