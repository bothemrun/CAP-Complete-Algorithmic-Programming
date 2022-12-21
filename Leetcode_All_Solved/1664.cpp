#include<assert.h>
class Solution {
public:
    int n;
    vector<long long> even_prefix;
    vector<long long> odd_prefix;
    inline long long range_sum(const int& low, const int& high, const bool& evenodd){
        //NOTE: left/right calls: 
        //NOTE: range(0, high) / range(low, n-1)
        if(!(low<=high))return 0;

        assert(0<=low && high<n);

        if(evenodd == false){
            //NOTE: not without (low-2>=0)?
            //NOTE: not (low>=0)? or (low>=1)?
            return even_prefix[high] - 
            ( (low-2>=0)?even_prefix[low-2]:0 );
        }else{
            return odd_prefix[high] - 
            ( (low-2>=0)? odd_prefix[low-2]:0 );
        }
    }
    int waysToMakeFair(vector<int>& nums) {
        n = nums.size();
        
        even_prefix.resize(n);
        odd_prefix.resize(n);

        even_prefix[0] = nums[0];

        if(n <= 1)return 1;
        odd_prefix[1] = nums[1];

        for(int i=2;i<n;i++){
            if(i%2 == 0)
                even_prefix[i] = nums[i] + even_prefix[i-2];
            else odd_prefix[i] = nums[i] + odd_prefix[i-2];
        }

        int cnt = 0;
        int even_max = ((n-1)%2==0)? (n-1):(n-2);
        int odd_max = ((n-1)%2==1)? (n-1):(n-2);
        for(int i=0;i<n;i++){
            int pre_e, pre_o, nex_e, nex_o;
            if(i%2 == 0){
                pre_e = i-2;
                pre_o = i-1;
                nex_e = i+2;
                nex_o = i+1;
            }else{
                pre_e = i-1;
                pre_o = i-2;
                nex_e = i+1;
                nex_o = i+2;
            }

            if(range_sum(0, pre_e, false) + range_sum(nex_o, odd_max, true) == 
                range_sum(1, pre_o, true) + range_sum(nex_e, even_max, false) ){
                cnt++;
            }
        }
        return cnt;
    }
};
