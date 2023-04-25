#include<stack>
#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> monosta_nondec;//non-decreasing, from the back
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(monosta_nondec.size() != 0 && !( monosta_nondec.top() <= prices[i]) )
                monosta_nondec.pop();
            
            ans[i] = prices[i] - ( (monosta_nondec.size()==0)? 0:monosta_nondec.top() );

            monosta_nondec.push(prices[i]);
        }
        return ans;
    }
};
