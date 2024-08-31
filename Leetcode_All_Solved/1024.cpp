//O(n * time range) = O(100^2) dp
#define inf_add(a,b) ( (a==INT_MAX || b==INT_MAX)? INT_MAX:(a+b) )
#define max_time 100

class Solution {
public:
    int n;
    int time;

    vector<vector<int>> memo;
    const int notyet = (-1);
    const int impossible = INT_MAX;

    int subset_last(const vector<vector<int>>& clips, int i, int last_end=0){
        if(i==n) return (time <= last_end)? 0:impossible;

        if(time <= last_end) return 0;

        if(last_end < clips[i][0]) return impossible;

        if(memo[i][last_end] != notyet) return memo[i][last_end];

        //choose or skip
        return memo[i][last_end] = min(
            subset_last(clips, i+1, last_end),
            inf_add(
                1,
                subset_last(clips, i+1, max(last_end, clips[i][1] ) ) //trap
            )
        );
    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        this->n = clips.size();
        this->time = time;

        function<bool(const vector<int>&, const vector<int>&)> cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        };
        sort(clips.begin(), clips.end(), cmp);

        memo.resize(n, vector<int>(max_time + 2, notyet));

        int ans = subset_last(clips, 0);
        return (ans==impossible)? (-1):ans;
    }
};
