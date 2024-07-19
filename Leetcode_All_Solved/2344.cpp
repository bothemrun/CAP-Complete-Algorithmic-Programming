//gcd(a, b) in O(log(min(a, b)))

//n := nums.size(), m := numsDivide.size()
//O( mlog(min(1e9)) + n )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline int gcd(int a, int b){
        if(b==0) return a;
        //assume a>=b
        return gcd(b, a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g_all = numsDivide.front();
        for(const int& x: numsDivide){
            g_all = (x>=g_all)? gcd(x, g_all):gcd(g_all, x);

            if(g_all == 1) break;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(g_all % nums[i] == 0) return i;
        }
        return (-1);
    }
};
