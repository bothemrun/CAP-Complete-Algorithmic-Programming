//m0

//enumerate each "border of a and b", by the help of prefix sum.
//then delete b before that border, and delete a after that border

//O(n)

//feels like prefix sum problem, not DP.

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
    inline void make_prefix(const string& s, vector<int>& prefix, const char& c){
        prefix.front() = s.front() == c;
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + ( s[i] == c );
    }

    inline int rangesum(const int& low, const int& high, const vector<int>& prefix){
        if(!(low <= high)) return 0;
        
        if(low == 0) return prefix[high];
        return prefix[high] - prefix[low-1];
    }

    int minimumDeletions(string s) {
        n = s.size();
        vector<int> prefixsum_b(n);
        vector<int> prefixsum_a(n);
        
        make_prefix(s, prefixsum_b, 'b');
        make_prefix(s, prefixsum_a, 'a');

        
        int min_del = n;
        for(int first_b=0;first_b<=n;first_b++){
            int b_del = rangesum(0, first_b-1, prefixsum_b);
            int a_del = rangesum(first_b, n-1, prefixsum_a);

            min_del = min(
                min_del,
                b_del + a_del
            );
        }

        return min_del;
    }
};
