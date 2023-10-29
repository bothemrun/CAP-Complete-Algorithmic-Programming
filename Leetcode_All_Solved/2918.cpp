//m0
#include<algorithm>
#include<assert.h>
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(const int& x: nums1){
            sum1 += x;
            if(x == 0) cnt1++;
        }
        for(const int& x: nums2){
            sum2 += x;
            if(x == 0) cnt2++;
        }

        
        if(sum1 > sum2){
            swap(sum1, sum2);
            swap(cnt1, cnt2);
        }
        assert(sum1 <= sum2);
        //raise sum1 to sum2
        if(cnt1==0){
            if(sum1 == sum2){
                if(cnt2 == 0){
                    return sum1;
                }else{
                    return (-1);
                }
            }else{
                return (-1);
            }
        }
        long long ans = sum2;
        
        //both raised up, feed
        assert(cnt1 > 0);
        //cnt1--;
        int old_cnt1 = cnt1;
        if(sum1 != sum2){
            cnt1--;
        }
        
        if(cnt1==0 && cnt2==0){
            return ans;
        }else if(cnt1==0){
            ans += (long long)cnt2;
            return ans;
        }else if(cnt2 == 0){
            long long diff = sum2 - sum1;
            cnt1++;
            if(diff >= cnt1){
                return sum2;
            }else{
                return (-1);
            }
        }
        
        long long diff = sum2 - sum1;
        cnt1 = max((long long)0, (long long)old_cnt1 - diff);
        long long feed = max(cnt1 , cnt2);
        ans += feed;
        return ans;
    }
};
