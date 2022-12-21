

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long odd_cnt = 0;
        long long n = nums.size();
        long long odd_low = 0;
        while(odd_low<n){
            while(odd_low<n && !( nums[odd_low]%2 == 1) )
                odd_low++;
            if(!(odd_low<n))break;
            
            long long odd_high = odd_low;
            while(odd_high+1<n && nums[odd_high+1]%2 == 1 )
                odd_high++;
            
            long long k = odd_high - (odd_low-1);
            //NOTE: C(k, 2) + k = number of subarrays of length k
            odd_cnt += (k*(k-1))/2 + k;

            //update
            odd_low = odd_high + 2;
        }

        return (n*(n-1))/2 + n - odd_cnt;
    }
};
