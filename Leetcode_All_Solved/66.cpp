#include<stack>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> sta;
        digits.back()++;
        for(int i=digits.size()-1;i>=1;i--){
            digits[i-1] += digits[i]/10;
            sta.push(digits[i]%10);
        }

        vector<int> ans;
        if(digits.front() >= 10){
            ans.push_back(1);
        }
        ans.push_back(digits.front()%10);

        while(sta.size() != 0){
            ans.push_back(sta.top());
            sta.pop();
        }
        return ans;
    }
};
