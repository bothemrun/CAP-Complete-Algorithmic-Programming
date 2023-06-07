//m1
//grow upwards, then grow leftwards & rightwards.

//but to improve from O(n^3) to O(n^2), use monotonic stack to find left & right bounds.
//for a cell (i, j), left := leftmost index such that height[index~j] all >= height[j]
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
    int m, n;
    inline void monotonic_stack(const vector<int>& height, vector<int>& bound, const int& delta){
        int start = (delta==1)? 0:(n-1);
        int end = (delta==1)? (n-1):0;

        stack<int> monosta;
        for(int j=start; j*delta <= end*delta ;j+=delta){
            
            while(monosta.size() && !( height[ monosta.top() ] < height[j] ) )
                monosta.pop();
            
            if(monosta.size() == 0)
                bound[j] = (delta==1)? 0:(n-1);
            else bound[j] = monosta.top() + delta;

            monosta.push(j);
        }
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix.back().size();

        int max_rec = 0;
        vector<int> height(n, 0);
        vector<int> left(n);
        vector<int> right(n);

        for(int i=0;i<m;i++){
            //height
            for(int j=0;j<n;j++)
                height[j] = (matrix[i][j] == '1')? (height[j]+1):0;
            
            //but to improve from O(n^3) to O(n^2), use monotonic stack to find left & right bounds.
            //for a cell (i, j), left := leftmost index such that height[index~j] all >= height[j]
            monotonic_stack(height, left, 1);
            monotonic_stack(height, right, (-1));

            for(int j=0;j<n;j++)
                max_rec = max(max_rec, height[j] * ( right[j] - (left[j]-1) ) );
        }

        return max_rec;
    }
};
