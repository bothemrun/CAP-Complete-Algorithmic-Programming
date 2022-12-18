#include<stack>
#include<utility>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> suffix_max;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=n-1;i>=0;i--){
            while( suffix_max.size() != 0 && !(temperatures[i] < suffix_max.top().first) ){
                //NOTE: for those smaller and further than me, just use me instead of them.
                suffix_max.pop();
            }

            if(suffix_max.size() != 0){
                ans[i] = suffix_max.top().second - i;
            }//else ans[i] already 0

            //update
            suffix_max.push( pair<int,int>(temperatures[i], i) );
        }

        return ans;
    }
};
