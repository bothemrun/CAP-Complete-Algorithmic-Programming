//m0

//A. its sorted property --> 378	Kth Smallest Element in a Sorted Matrix	medium

//1. view the paris as a matrix.


//B. check a bound

//1. as in 378, we can check in O(n).


//C. can we bound the floating point?

//1. the min diff is by choosing neighbors as the numerator or denominator.
//2. (a+1)/b - a/b = 1/b --> 1/max_val
//3. a/b - a/(b+1) = a*( (b+1) - b ) / (b*(b+1)) = a/( b*(b+1)) ) --> 1/max_val^2


//D. time for binary search?

//1. time to halve to min diff = (1/2)^t = 1/m^2
//2. t = log(m^2)


//E. time complexity
//1. O(n * logm^2)


//F. duplicates as in 378?

//1. no, since they're primes; no p*q = r*s


//G. binary search delta / left right intervals ?

//1. mid-1 / [low, mid], [mid+1, high] ??
//2. atypical binary --> no checking delta / [low, mid], [mid, high]


//H. which pair makes this floating point?

//1. when checking the bound, find the pair making the max fraction.


//I. 
//1. floating point binary search is tricky
//2. refernce: top solution by fun4LeetCode

#define ti3  tuple<int,int,int>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, k;
    vector<int> ans;

    inline ti3 smaller_cnt(const vector<int>& arr, const double bound){
        double max_fraction = 0;
        int arr_i = (-1), arr_j = (-1);

        int cnt=0;
        int j=0;

        for(int i=0;i<n;i++){
            while(j<n && !( (double)arr[i] / (double)arr[j] <= bound ) ){
                j++;
            }

            if(j==n) break;

            cnt += (n-1) - (j-1);

            //which pair makes the bound?
            if( (double)arr[i] / (double)arr[j] > max_fraction ){
                max_fraction = (double)arr[i] / (double)arr[j];

                arr_i = arr[i];
                arr_j = arr[j];
            }
        }

        return {cnt, arr_i, arr_j};
    }

    void binary(const vector<int>& arr, double low, double high){
        double mid = (low+high)/2;

        auto [cnt, arr_i, arr_j] = smaller_cnt(arr, mid);

        //no checking delta
        if(cnt == k){
            ans = {arr_i, arr_j};
            return;
        }

        //atypical intervals
        if(cnt<k) binary(arr, mid, high);
        else binary(arr, low, mid);
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        n = arr.size();
        this->k = k;

        binary(arr, (double)arr[0] / (double)arr[n-1], 1);
        return ans;
    }
};
