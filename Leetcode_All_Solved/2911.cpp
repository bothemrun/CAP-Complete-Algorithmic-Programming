//m0
//[A] the hard part is the definition, computation & complexity of semi-palindrome costs.

//[B] O(n^3 logn) = O(1.8e7)
//other top solutions like lee215 actually in O(n^3 logn)

//2100ms 5%, but lee215 & wisdompeak's runtime are good.



//[C] bound on the number of factors/divisors:

//1. larger bound: 2*sqrt(n)

//2. log(n) on average
//2.1. https://terrytao.wordpress.com/2008/09/23/the-divisor-bound/

#define inf_add(a,b) ( (a==INT_MAX||b==INT_MAX)? INT_MAX:(a+b) )

class Solution {
public:
    int n;
    vector<vector<int>> factors;

    const int notyet = (-1);
    const int impossible = INT_MAX;
    vector<vector<int>> memo_semi;
    vector<vector<int>> memo;

    //O(n * sqrt(n))
    inline void len2factors(const int max_len){
        factors.resize(max_len + 1);
        for(int len=2;len<=max_len;len++){
            //d=1, but not len itself.

            //wrong: it's prime factorization that any number has at most 1 prime factor >= sqrt(number)
            //for(int f=1;f<=sqrt(len);f++)if(len%f == 0){

            for(int f=1;f<=len/2;f++)if(len % f == 0){
                factors[len].push_back(f);
            }
        }
    }

    //only used once by the specific change(i, j), which is cached.
    //O(n)
    inline int semi_palin_cost(const string& s, int i, int j, int d){
        
        int cost = 0;
        /*
        const int len = j - (i-1);
        const int step = len/d;
        for(int start=i+0;start<i+d;start++){
            //int end = (len-1) - (d-1) + start;
            int end = start + (d-1)*step; //d is the group number
        */
        for(int t=0;t<d;t++){
            int start = i + t;
            int end = j - (d-1) + t;

            while(start<end){
                if(s[start] != s[end]){
                    cost++;
                }

                //update
                start += d;
                end -= d;
            }
        }
        return cost;
    }

    //O(n^2 * logn) self, O(n^3 * logn) totally
    int min_cost(const string& s, int i, int j){
        int len = j - (i-1);
        int ret = INT_MAX;
        for(const int& d: factors[len]){
            ret = min(
                ret,
                semi_palin_cost(s, i, j, d)
            );
        }
        return memo_semi[i][j] = ret;
    }

    int enum_partition(const string& s, int i, int part){
        //each part only has 1 char, impossible to form semi-palindromes.
        if(i - (0-1) <= part) return impossible;

        if(part==1) return min_cost(s, 0, i);

        if(memo[i][part] != notyet) return memo[i][part];

        int ret = impossible;
        //length 1 is impossible for semi-palindromes
        for(int j=0;j+1<i;j++){
            ret = min(
                ret,
                inf_add(
                    min_cost(s, j+1, i),
                    enum_partition(s, j, part-1)
                )
            );
        }
        return memo[i][part] = ret;
    }

    int minimumChanges(string s, int k) {
        this->n = s.size();
        len2factors(n);

        memo_semi.resize(n, vector<int>(n, notyet));
        memo.resize(n, vector<int>(k+1, notyet));

        return enum_partition(s, n-1, k);
    }
};
