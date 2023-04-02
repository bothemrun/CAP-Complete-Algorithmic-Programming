#include<algorithm>
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt0 = 0, cnt1 = 0;
        int n = s.size();
        int max_bal = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                if(i-1>=0 && s[i-1] == '1'){
                    cnt0 = 1;
                }else{
                    cnt0++;
                }
                
                cnt1 = 0;
            }else{
                cnt1++;
                
                //if(cnt0 == cnt1){
                if(cnt0 >= cnt1){
                    //max_bal = max(max_bal, 2*cnt0);
                    max_bal = max(max_bal, 2 * cnt1);
                }
            }
        }
        
        return max_bal;
    }
};
