//m0

//1. (x, y) to new coordinates (a, b) = (x+y, x-y)

//2. manhattan distance = chebyshev distance of (a, b) = max(|a1-a2|, |b1-b2|)

//3. for 3D:
//a. apply +z/-z to (x+y, x-y) 
//b. (x+y +z, x+y -z, x-y +z, x-y -z)


//4. see
//a. see my Leetcode Log notes
//b. https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/
//c. https://codeforces.com/blog/entry/57534


//5. O(n) on averge due to nth_element()
//a. can also use sort() in O(nlogn)

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

    inline int max_manhattan(const int ban){
        int a_front = (ban == get<1>( p[0].front() ) )? 1:0;
        int a_back = (ban == get<1>( p[0].back() ) )? (n-2):(n-1);

        int b_front = (ban == get<1>( p[1].front() ) )? 1:0;
        int b_back = (ban == get<1>( p[1].back() ) )? (n-2):(n-1);

        return max(
            get<0>( p[0][a_back] ) - get<0>( p[0][a_front] ),
            get<0>( p[1][b_back] ) - get<0>( p[1][b_front] )
        );
    }

    int minimumDistance(vector<vector<int>>& points) {
        this->n = points.size();
        p.resize(2, vector<tii>(n));
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];

            p[0][i] = {x+y, i};
            p[1][i] = {x-y, i};
        }

        int ans = INT_MAX;
        for(int d=0;d<2;d++)
            sort(p[d].begin(), p[d].end());

        for(int d=0;d<2;d++){
            auto [ma, ma_i] = p[d].back();
            ans = min(
                ans,
                max_manhattan(ma_i)
            );

            auto [mi, mi_i] = p[d].front();
            ans = min(
                ans,
                max_manhattan(mi_i)
            );
        }

        return ans;
    }
};
