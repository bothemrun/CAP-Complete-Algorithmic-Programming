//NOTE: for nums[i] it needs last smaller, and monotonic stack has the property of "132".

//NOTE: trap: count itself.
#include<stack>
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = n;//NOTE: count itself

        stack<int> monosta;
        for(int i=n-1;i>=0;i--){
            //NOTE: "132" property
            while(monosta.size() && !( nums[ monosta.top() ] < nums[i])) monosta.pop();

            if(monosta.size() == 0)
                cnt += (n-1) - i;
            else cnt += ( monosta.top() - 1 ) - i;

            monosta.push(i);
        }

        return cnt;
    }
};
