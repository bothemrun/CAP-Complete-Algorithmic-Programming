//m1

//[Thinking Process]

//[A] (x, y) to new coordinates (a, b) = (x+y, x-y)

//[B] Manhattan Distance = Chebyshev distance of (a, b) = max(|a1-a2|, |b1-b2|)


//[C] See Also:

//a. https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/
//b. https://codeforces.com/blog/entry/57534
//c. my Leetcode Log notes.


//[D] Complexity = O(n)

//a. due to nth_element() with O(n) on average.
//( b. can also use sort() in O(nlogn) )

#define tii tuple<int, int>
#include<tuple>
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
    int n;
    vector<vector<tii>> p;

    inline int max_manhattan(const int remove_i){
        int a_front = (remove_i == get<1>( p[0].front() ) )? 1:0;
        int a_back = (remove_i == get<1>( p[0].back() ) )? (n-2):(n-1);

        int b_front = (remove_i == get<1>( p[1].front() ) )? 1:0;
        int b_back = (remove_i == get<1>( p[1].back() ) )? (n-2):(n-1);

        return max(
            get<0>( p[0][a_back] ) - get<0>( p[0][a_front] ),
            get<0>( p[1][b_back] ) - get<0>( p[1][b_front] )
        );
    }

    int minimumDistance(vector<vector<int>>& points) {
        this->n = points.size();
        p.resize(2, vector<tii>(n) );
        for(int i=0;i<n;i++){
            p[0][i] = { points[i][0] + points[i][1], i };
            p[1][i] = { points[i][0] - points[i][1], i };
            /* //equivalent clear code:
            int x = points[i][0];
            int y = points[i][1];

            p[0][i] = {x+y, i};
            p[1][i] = {x-y, i};
            */
        }

        for(int d=0;d<2;d++){
            nth_element( p[d].begin(), p[d].begin() + (n-2), p[d].end() );

            nth_element( p[d].begin(), p[d].begin() + 1, p[d].begin() + (n-2) );
        }

        int ans = INT_MAX;
        for(int d=0;d<2;d++){
            const auto& [mi, mi_i] = p[d][0];
            ans = min(
                ans,
                max_manhattan(mi_i)
            );

            const auto& [ma, ma_i] = p[d][n-1];
            ans = min(
                ans,
                max_manhattan(ma_i)
            );
        }

        return ans;
    }
};
