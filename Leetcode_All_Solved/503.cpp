#include<stack>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> monosta;
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--){
            while(monosta.size() != 0 && !( nums[i%n] < monosta.top()) ){
                monosta.pop();
            }

            if(i < n){
                if(monosta.size() == 0)ans[i] = (-1);
                else ans[i] = monosta.top();
            }

            monosta.push(nums[i%n]);
        }

        return ans;
    }
};
