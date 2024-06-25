//for the leftmost 0 bit, no's gonna help it. it must help itself. --> greedy
//O(n)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int flip = 0;
        for(const int& x: nums)if( (x ^ (flip%2)) == 0){
            flip++;
        }
        return flip;
    }
};
