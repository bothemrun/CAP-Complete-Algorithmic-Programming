//m0
//grow upwards, then grow leftwards & rightwards.
//it help 85. Maximal Rectangle.
//3 pass O(n)
#include<stack>
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
    inline void monotonic_stack(const vector<int>& heights, vector<int>& bound, const int& start, const int& end, const int& delta){
        stack<int> monosta;
        for(int i=start; delta*i <= delta*end ;i+=delta){
            while(monosta.size() && !( heights[ monosta.top() ] < heights[i] ) )
                monosta.pop();
            
            bound[i] = (monosta.size()==0)? start:( monosta.top() + delta );

            monosta.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_rec = 0;

        vector<int> left(n);
        vector<int> right(n);
        monotonic_stack(heights, left, 0, n-1, 1);
        monotonic_stack(heights, right, n-1, 0, (-1));

        for(int i=0;i<n;i++)
            max_rec = max(
                max_rec,
                heights[i] * ( right[i] - (left[i]-1) )
            );
        return max_rec;
    }
};
