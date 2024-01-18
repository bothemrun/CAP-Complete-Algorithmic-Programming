//O(n)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int sum = 0;
        for(int i=0;i<n;i++)if(grumpy[i] == 0)
            sum += customers[i];
        
        int ans = 0;

        //1st window
        int window = 0;
        for(int i=0;i<minutes-1;i++)if(grumpy[i] == 1)
            window += customers[i];
        
        for(int i=0; i + (minutes-1)<n;i++){
            //update, push
            int right = i + (minutes-1);
            if(grumpy[right] == 1) window += customers[right];

            ans = max(ans, sum + window);

            //update, drop
            if(grumpy[i] == 1) window -= customers[i];
        }

        return ans;
    }
};
