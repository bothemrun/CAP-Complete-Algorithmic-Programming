//O(n^2) dp partition
#define notyet (-1)
#define impossible INT_MAX
#include<limits.h>
#include<algorithm>
#include<unordered_set>

class Solution {
public:
    unordered_set<string> pow5;

    vector<int> memo;
    int enum_partition(const string& s, const int& i){
        if(i < 0) return 0;

        if(memo[i] != notyet) return memo[i];

        //1 partition [j, i]
        int ret = impossible;
        for(int j=0;j<=i;j++){
            if(s[j] == '0') continue;
            if( pow5.count( s.substr(j, i - (j-1) ) ) == 0) continue;

            int sub = enum_partition(s, j-1);
            if(sub != impossible)
                ret = min(
                    ret,
                    1 + sub
                );
        }

        return memo[i] = ret;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();

        //2^16 = 6e4
        //5^7 = 7e4
        int p5 = 1;
        for(int p=0;p<=7;p++){
            int x = p5;
            string s5 = "";
            while(x != 0){
                s5 += to_string( x%2 );
                x /= 2;
            }
            reverse(s5.begin(), s5.end());

            pow5.insert(s5);

            //update
            p5 *= 5;
        }

        memo.resize(n, notyet);

        int ans = enum_partition(s, n-1);

        return (ans==impossible)? (-1):ans;
    }
};
