class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;
        //[i, j] alter
        long long i=0;
        while(i<n){
            long long j=i;
            while(j+1<n && nums[j] != nums[j+1]){
                j++;
            }
            
            long long len = j - (i-1);
            ans += len * (len+1) / 2;
            
            //udpate
            i = j+1;
        }
        return ans;
    }
};
