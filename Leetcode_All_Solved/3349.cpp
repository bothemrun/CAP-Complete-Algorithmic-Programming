class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int a=0;a<n;a++){
            int b = a+k;
            if(!(b<n)) return false;
            bool next = false;
            for(int i=a;i+1<=b-1;i++){
                if(!( nums[i] < nums[i+1] )){
                    next = true;
                    break;
                }
            }
            if(!( b+k-1 < n )) return false;
            for(int i=b;i+1<=b+k-1;i++){
                if(!( nums[i] < nums[i+1] )){
                    next = true;
                    break;
                }
            }
            if(next == true) continue;
            return true;
        }
        return false;
    }
};
