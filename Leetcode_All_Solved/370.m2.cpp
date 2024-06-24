//m2

//difference array in O(n). vanilla 1D line sweep needs O(nlogn)

//O(1) space by reusing difference array as the answer vector

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //since the answer vector uses int, assume no overflow
        vector<int> diff(length, 0);
        for(const vector<int>& update: updates){
            diff[update[0]] += update[2];

            if(update[1] + 1 < length) diff[update[1] + 1] -= update[2];
        }

        //since the answer vector uses int, assume no overflow
        int sweep = 0;
        for(int& x: diff){
            sweep += x;

            x = sweep;
        }
        return diff;
    }
};
