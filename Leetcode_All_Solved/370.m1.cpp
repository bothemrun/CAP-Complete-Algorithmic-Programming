//m1

//difference array in O(n). vanilla 1D line sweep needs O(nlogn)
#define max_len ((int)1e5)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //difference array with size = n+1
        long long diff[max_len + 1] = {0};

        for(const vector<int>& update: updates){
            diff[update[0]] += update[2];
            diff[update[1] + 1] -= update[2];
        }

        vector<int> ans(length, 0);
        long long sweep = 0;
        for(int i=0;i<length;i++){
            sweep += diff[i];

            ans[i] = sweep;
        }
        return ans;
    }
};
