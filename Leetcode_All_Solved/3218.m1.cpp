//m1

//copied from 3219. Minimum Cost for Cutting Cake II


//[A] the total cost of horizontal[i] = horizontal[i] * (count of vertical cuts before)

//[B] horizontal cuts don't influence other horizontal cuts.

//[C] so the order of horizontal cuts is sorted by horizontal[i] increasingly, 'cuz the count of vertical cuts is increasing too.

//[D] fix horizontal cut.
//1. now the remaining problem is to determine how to place vertical cuts in between the horizontal cuts.

//[E] optimization --> dp/binary search/greedy?
//1. there are many values to be determined. so not binary.
//2. the values of both costs vary.  no obvious strategies like placing all vertical cuts in front. --> not greedy.

//[F] knapsack dp(hori_i, verti_cnt), each recursion in O(m).
//1. O(m * n^2) TLE


/////////////end of 3218. Minimum Cost for Cutting Cake I.


//[G] greedy choice:

//1. think of a result with some h[i] not > v[i] in a neighboring interval.
//2. swapping v's won't affect the value. --> now h[i] & v[i] right neighboring.
//3. further swapping h[i] & v[i] make the value -= h[i] += v[i] --> better result.

//4. greedy proof QED. --> the order = sort the whole horizonalCut concat verticalCut decreasingly.


//[H] implement
//1. like merging 2 sorted list in O(m+n)

//(mlogm + nlogn + m+n)

#define coef(size) (1 + size)
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

        /* //420ms, greater<int>() 220ms
        function<bool(const int&, const int&)> cmp = [](const int& a, const int& b){
            return a>b;
        }; */
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>() );
        sort(verticalCut.begin(), verticalCut.end(), greater<int>() );


        int hsize = m-1;
        int vsize = n-1;

        long long ans = 0;
        int i=0, j=0;
        while(i<hsize && j<vsize){
            if(horizontalCut[i] > verticalCut[j]){
                ans += coef( (j-1) + 1 ) * horizontalCut[i++];
            }else{
                ans += coef( (i-1) + 1 ) * verticalCut[j++];
            }
        }

        if(i<hsize){
            ans += coef(vsize) * accumulate( horizontalCut.begin()+i, horizontalCut.end(), 0 );
        }
        if(j<vsize){
            ans += coef(hsize) * accumulate( verticalCut.begin()+j, verticalCut.end(), 0 );
        }
        return ans;
    }
};
