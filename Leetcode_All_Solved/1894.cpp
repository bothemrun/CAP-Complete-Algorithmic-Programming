//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum_all = 0;
        for(const int& x: chalk) sum_all += x;
        long long remain = (long long)k % sum_all;

        for(int i=0;i<n;i++){
            if(remain < chalk[i]) return i;
            remain -= chalk[i];
        }
        assert(false);
        return (-1);
    }
};
