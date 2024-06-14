//O(n^2)
#define alphabet 26

class Solution {
public:
    vector<int> memo;
    const int notyet = (-1);

    int enum_partition(const string& s, int i){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        int ret = INT_MAX;//must exist finite partition.
        //enum this 1 part
        int cnt[alphabet] = {0};
        int ma = 0;

        for(int j=i;j>=0;j--){
            cnt[ s[j]-'a' ]++;
            ma = max(ma, cnt[ s[j]-'a' ] );

            bool equal_f = true;
            for(int c=0;c<alphabet;c++)if(cnt[c] != 0 && cnt[c] != ma){
                equal_f = false;
                break;
            }

            if(equal_f)
                ret = min(
                    ret,
                    1 + enum_partition(s, j-1)
                );
        }

        return memo[i] = ret;
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        memo.resize(n, notyet);

        return enum_partition(s, n-1);
    }
};
