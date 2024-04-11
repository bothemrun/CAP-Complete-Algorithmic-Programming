//O(n)
//critical part is to handle all edge cases.

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
    string removeKdigits(string num, int k) {
        int n = num.size();

        //edge
        if(k==n) return "0";

        stack<char> sta;
        sta.push(num.front());

        int cur_i = 1;

        int t=0;
        while(t<k && cur_i<n){
            char cur = num[cur_i++];

            while(sta.size() && sta.top() > cur && t<k){
                sta.pop();
                t++;
            }
            sta.push(cur);
        }

        string ans = "";
        while(sta.size()){
            ans += sta.top();
            sta.pop();
        }

        assert(k-t < ans.size());
        ans = ans.substr(k-t);

        reverse(ans.begin(), ans.end());

        ans += num.substr(cur_i);

        //edge
        if(ans.size()==0) return "0";

        //edge
        int j = 0;//leading 0
        while(j<ans.size() && ans[j] == '0'){
            j++;
        }
        
        //edge
        if(j==ans.size()) return "0";

        return ans.substr(j);
    }
};
