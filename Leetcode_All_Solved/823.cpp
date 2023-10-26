//O(n^2) recursion with memo
//pre-compute the possible products of the root
#define mod ((long long)1e9 + 7)
#define PII pair<int,int>
#define notyet (-1)
#include<utility>
#include<algorithm>
#include<unordered_map>

class Solution {
public:
    vector<vector<PII>> idx2product;

    vector<long long> memo;
    long long enum_root(const int& root_i){
        if(memo[root_i] != notyet) return memo[root_i];

        long long cnt = 1;//self as a tree
        for(const auto& [j, k]: idx2product[root_i])
            cnt = (
                cnt +
                (
                    enum_root(j) *
                    enum_root(k)
                )%mod
            )%mod;

        return memo[root_i] = cnt;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        //pre-compute
        unordered_map<int, int> arr2idx;
        sort(arr.begin(), arr.end());
        //arr all unique
        for(int i=0;i<n;i++) arr2idx[ arr[i] ] = i;

        idx2product.resize(n);

        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++)if( arr[i]%arr[j]==0 && arr2idx.count(arr[i]/arr[j]) ){
                idx2product[i].push_back( PII( j, arr2idx[ arr[i]/arr[j] ] ) );
            }
        }


        memo.resize(n, notyet);
        long long ans = 0;
        for(int i=0;i<n;i++)
            ans = (
                ans +
                enum_root(i)
            )%mod;
        return ans;
    }
};
