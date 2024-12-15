//[Thinking Process]

//[A] observation: not optimal
//1. monotonically increase or decrease
//2. doing op 3 on a & b, then on b & c is the same as decreasing a & increasing c.
//3. so the only case for op 3 is neighboring characters.

//[B] simplified problem: forbid operation 3
//1. enumerate target = 0 ~ max frequency in O(n).
//2. for each char, to 0 or to target --> min(f, |target - f|)
//3. ans = sum of 2.

//[C] for op 3, it's related to the i+1 or i+2 suffix subproblems
//1. so 1D dp
//2. x := cnt[i], y := cnt[i+1]
//3. min( [B], [D] or [E] )

//[D] op3 cases: y >= target
//1. can't use op3, since y can only decrease
//2. just use [B].

//[E] op3 cases: y < target
//1. (case x > target) --> x down to target --> max(x - target, target - y)
//2. (case x < target) --> x down to 0 --> max(x, target - y)
//3. (case x == target) --> don't use op 3.

//[F] O(enum all targets * alphabet) = O(n * 26)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int alphabet = 26;

    const int notyet = (-1);
    vector<int> memo;

    int enum_next2(const vector<int>& cnt, const int target, const int i){
        if(i>=alphabet) return 0;

        if(memo[i] != notyet) return memo[i];

        //use op 1 or 2
        int ret = enum_next2(cnt, target, i+1) + min( cnt[i] - 0, abs( cnt[i] - target ) );
        if(i+1>=alphabet) return memo[i] = ret;

        const int x = cnt[i];
        const int y = cnt[i+1];
        if(y >= target) return memo[i] = ret;

        if(x > target){
            ret = min(
                ret,
                enum_next2(cnt, target, i+2) +
                max(x - target, target - y)
            );
        }else if(x < target){
            ret = min(
                ret,
                enum_next2(cnt, target, i+2) +
                max(x - 0, target - y)
            );
        }
        return memo[i] = ret;
    }

    int makeStringGood(string s) {
        vector<int> cnt(alphabet, 0);
        for(const char c: s){
            cnt[c - 'a']++;
        }
        const int max_cnt = *max_element(cnt.begin(), cnt.end());

        int ans = (int)s.size();
        for(int target=0;target<=max_cnt;target++){
            //XXX: syntax trap: without clear(), resize won't reset the values.
            memo.clear();
            memo.resize(alphabet, notyet);

            ans = min(
                ans,
                enum_next2(cnt, target, 0)
            );
        }
        return ans;
    }
};
