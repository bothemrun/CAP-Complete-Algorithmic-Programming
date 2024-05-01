//m0
//d := nums1 - nums2
//i<j means i != j here

//0 < d[i] + d[j]
//so for each i, count j with -d[i] < d[j]
//then ans /= 2

//finally, subtract 0 < d[i] for i == j cases.
//O(nlogn)

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
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        vector<int> d(n);
        for(int i=0;i<n;i++) d[i] = nums1[i] - nums2[i];

        sort(d.begin(), d.end());

        long long ans = 0, self = 0;

        for(const int& x: d){
            int j = upper_bound(d.begin(), d.end(), -x) - d.begin();

            ans += n - j;

            self += x>0;
        }

        return (ans-self)/2;
    }
};
