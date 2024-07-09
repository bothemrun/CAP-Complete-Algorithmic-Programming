//m0
//1. 2D bottom up DP
//2. why can't we use top down DP?



//[A] easily fall into O(n*k^2).
//optimization inspired by:

//(1) lee215.

//(2) the fact that the subs must be alternating like: abababa...
//so we don't need states for all k remainders, just pass those 2 alternating remainders
//--> all solutions use this fact.  so inevitable.

//proof:
//if a+b = mk+r, b+c = nk+r, can a != c ??

//a-c = (m-n)k = 0(mod k)
//since a,b,c are all remainders 0~k-1, a == c. QED.


//(3) the information / states of (1) val = (sub[0]+sub[1])%k, (2) last chosen remainder are indispensable. --> omitting 1 of them can generate different subsequences.

//hence, the 1 state we drop is the index i.
//--> standard dp memory optimzation.
//--> also, we can't use top down DP without i.

#define max_k ((int)1e3)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        //memo(i, a, b) := for prefix nums[0, i], choose nums[i]%k == a,
        //length of subs with alternating remainders ...bababa,
        //which ends with a.
        //including length 1 subs: a
        int memo[max_k][max_k] = {0};
        int ans = 0;
        for(const int& a: nums){
            for(int b=0;b<k;b++){
                memo[a%k][b] = 1 + memo[b][a%k];

                ans = max(ans, memo[a%k][b]);
            }
        }

        return ans;
    }
};
