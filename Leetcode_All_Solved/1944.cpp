//O(n) by monotonic stack

//Thinking Process:
//1. think about a O(n^2) method.

//2. for i, between its next larger j [i+1, j-1],
//2.1. by the requirement, all visible must be in between [i+1, j-1].
//2.2. we maintain prefix max on the way from [i+1, j-1]
//2.3. if k in [i+1, j-1] has heights > the prefix max, then 1 more visible.

//3. then use monotonic stack for next  larger (last larger and iterate back for convenience)
//3.1. the the number of elements popped out is the visible count for i.
//3.2. because all "valleys" between monotonic stack elements are blocked by its higher monotonic stack element.

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
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        vector<int> ans(n, 0);
        stack<int> last_larger;

        for(int i=(n-1);i>=0;i--){

            while(
                last_larger.size() != 0 &&
                !( last_larger.top() > heights[i] )
            ){
                ans[i]++;
                last_larger.pop();
            }

            if(last_larger.size() != 0) ans[i]++;

            last_larger.push(heights[i]);
        }

        return ans;
    }
};
