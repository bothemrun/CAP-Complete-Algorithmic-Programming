//m1
//1. 1D bottom up DP
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


//[B] memory optimization: 2D to 1D DP:

//1. take the unrelated state to the outer loop.
//2. the memo is irrelavant for different vals.

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

        int ans = 0;
        for(int val=0;val<k;val++){
            //memo(c) := the subs ending with remainder c
            int memo[max_k] = {0};

            for(const int& a: nums){
                memo[a%k] = 1 + memo[ ( (val-a)%k + k )%k ];

                ans = max(ans, memo[a%k]);
            }
        }

        return ans;
    }
};
