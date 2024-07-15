//m0

//[A] j doesn't matter, just sort arr2.


//[B] dp(i) choose or skip the operation?

//1. don't have full info of operations previously done.


//[C] dp(i, prev number)
//1. prev number results in O( max(m, n) )


//[D] precompute the binary searches
//from O(mn * logn) to O(mn + mlogn)

//can be optimzed using vectors instead of a hash maps.

//O(nlogn) + O(mn + mlogn) = O(mn)

#define inf_add(a,b) ( (a==INT_MAX||b==INT_MAX)? INT_MAX:(a+b) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;

    const int impossible = INT_MAX;
    vector< unordered_map<int,int> > memo;

    unordered_map<int, int> memo_compat;
    int binary_compat(const vector<int>& arr2, int prev){
        if(memo_compat.count(prev) != 0) return memo_compat[prev];

        int j = upper_bound(
            arr2.begin(),
            arr2.end(),
            prev
        ) - arr2.begin();

        return memo_compat[prev] = (j<n)? arr2[j]:impossible;
    }

    int enum_prev(const vector<int>& arr1, const vector<int>& arr2, int i, int prev){
        if(i==m) return 0;

        if(memo[i].count(prev) != 0) return memo[i][prev];

        int compat = binary_compat(arr2, prev);

        int choose = impossible;
        if(compat != impossible){
            choose = inf_add(
                1,
                enum_prev(arr1, arr2, i+1, compat)
            );
        }

        if(!( prev < arr1[i] )){
            return memo[i][prev] = choose;
        }else{
            return memo[i][prev] = min(
                choose,
                enum_prev(arr1, arr2, i+1, arr1[i] )
            );
        }
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        this->m = arr1.size();
        this->n = arr2.size();

        sort(arr2.begin(), arr2.end());

        memo.resize(m);
        int ans = enum_prev(arr1, arr2, 0, INT_MIN);
        return (ans==impossible)? (-1):ans;
    }
};
