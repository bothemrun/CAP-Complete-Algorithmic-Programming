//m0
//binary search the answer. check if there are m*n // 2 + 1 >= this answer 
//(int division, including self)
//O( log(1e6) * mlogn )

#define max_grid ((int)1e6)
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
    int median_cnt;
    inline bool half_more_equal(const vector<vector<int>>& grid, const int& limit){
        int cnt = 0;

        for(const vector<int>& g: grid){
            auto it = lower_bound( g.begin(), g.end(), limit );
            int idx = it - g.begin();

            //ok for not found (it == .end() )
            cnt += (n-1) - (idx-1);
        }

        return cnt >= median_cnt;
    }

    int binary(const vector<vector<int>>& grid, const int& low, const int& high){
        int mid = low + (high-low)/2;

        bool mid_res = half_more_equal(grid, mid);
        if( mid_res && half_more_equal(grid, mid + 1) == false ) return mid;

        if(mid_res) return binary(grid, mid+1, high);
        else return binary(grid, low, mid);
    }

    int matrixMedian(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        median_cnt = m*n / 2 + 1;

        return binary(grid, 1, max_grid);
    }
};
