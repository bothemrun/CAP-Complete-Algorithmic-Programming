//m0

//[A] the total cost of horizontal[i] = horizontal[i] * (count of vertical cuts before)

//[B] horizontal cuts don't influence other horizontal cuts.

//[C] so the order of horizontal cuts is sorted by horizontal[i] increasingly, 'cuz the count of vertical cuts is increasing too.

//[D] fix horizontal cut.
//1. now the remaining problem is to determine how to place vertical cuts in between the horizontal cuts.

//[E] optimization --> dp/binary search/greedy?
//1. there are many values to be determined. so not binary.
//2. the values of both costs vary.  no obvious strategies like placing all vertical cuts in front. --> not greedy.

//[F] knapsack dp(hori_i, verti_cnt), each recursion in O(m).
//1. O(m * n^2) = 8e3

//O(sort + mn^2) = O(mlogm + nlogn + m*n^2) = 8e3

#define coef(size) (size + 1)

#define range_sum1(i, j) ( presum[j] - ( (i-1>=0)? presum[i-1]:0 ) )
#define range_sum(i, j) ( (i<=j)? range_sum1(i, j):0 )
#include<functional>

class Solution {
public:
    int hsize, vsize;//different definitions
    vector<int> presum;

    const int notyet = (-1);
    vector<vector<int>> memo;

    int knapsack(const vector<int>& hor, const vector<int>& ver, int i, int cnt){
        //i := fixed horizontal idx
        //cnt := variable vertical count before i-1
        if(i==hsize){
            int remain = vsize - cnt;
            assert(remain >= 0);

            return coef(hsize) * range_sum(vsize-remain, vsize-1);
        }

        if(memo[i][cnt] != notyet) return memo[i][cnt];

        int ret = INT_MAX;
        for(int more=0;more+cnt <= vsize;more++){
            int h_cost = hor[i] * coef(more+cnt);

            int v_cost = range_sum( (cnt-1) + 1, (cnt-1) + more ) * coef( (i-1) + 1 );

            ret = min(
                ret,
                h_cost + v_cost +
                knapsack(hor, ver, i+1, cnt + more)
            );
        }
        return memo[i][cnt] = ret;
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        hsize = m-1;
        vsize = n-1;

        function<bool(const int&, const int&)> cmp = [](const int& a, const int& b){
            return a>b;
        };
        sort(horizontalCut.begin(), horizontalCut.end(), cmp);
        sort(verticalCut.begin(), verticalCut.end(), cmp);

        presum.resize(vsize);

        //edge case
        if(vsize==0){
            return accumulate(horizontalCut.begin(), horizontalCut.end(), 0);
        }

        presum.front() = verticalCut.front();
        for(int i=1;i<vsize;i++) presum[i] = presum[i-1] + verticalCut[i];

        memo.resize(hsize, vector<int>(vsize + 1, notyet));
        return knapsack(horizontalCut, verticalCut, 0, 0);
    }
};
