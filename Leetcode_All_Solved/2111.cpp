//[Thinking Process]


//[A] Disentangled:

//1. ok, arr[i]'s gonna become some arr[i-l] later.  so who's gonna get affected exactly?

//2. not arr[i+1].  the affected forms {i+k, i+2k, i+3k,...} group.


//[B] Simplified Problem: the entangled k-group

//1. affected group: arr[i]<=arr[i+k], arr[i+k]<=arr[i+2k],... and so on.

//2. --> longest increasing (non-decreasing) subsequene.


//[C] LIS

//1. vanilla DP: O(k * LIS) = O(k * LIS(n/k) ) = O(k * (n/k)^2) = O(n^2 / k) TLE.

//2. so need LIS(m) in O(mlogm) --> 
//a. 1964	Find the Longest Valid Obstacle Course at Each Position	hard
//b. 300	Longest Increasing Subsequence	medium.

//O(k * LIS) = O(k * (n/k)log(n/k) ) = O(n * log(n/k))

#define ceil_div(a, b) ( a/b + ( (a%b==0)? 0:1 ) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline int LIS_tree(const vector<int>& arr, const int start, const int cnt, const int k){
        int max_lis = 0;

        vector<int> tree_arr;
        for(int t=0, i=start;t<cnt;t++, i += k){
            assert(i<n);

            auto it = upper_bound(tree_arr.begin(), tree_arr.end(), arr[i]);

            int lis = 0;
            //if empty, v.begin() == v.end()
            if(it == tree_arr.end()){
                tree_arr.push_back(arr[i]);

                lis = tree_arr.size();
            }else{
                int j = it - tree_arr.begin();

                //crucial: the replacement
                *it = arr[i];

                lis = j - (0-1);
            }

            max_lis = max(max_lis, lis);
        }
        return max_lis;
    }

    int kIncreasing(vector<int>& arr, int k) {
        this->n = arr.size();
        int ans = 0;

        for(int d=0;d<k;d++){
            int start = 0 + d;
            int nn = (n-1) - (start-1);
            //count of elements in this k-group
            int cnt = ceil_div(nn, k);

            ans += (
                cnt -
                LIS_tree(arr, start, cnt, k)
            );
        }
        return ans;
    }
};
