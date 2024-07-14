//m1

//[A] the hard part is the definition, computation & complexity of semi-palindrome costs.

//[B] O(n^3 logn) = O(1.8e7)
//other top solutions like lee215 actually in O(n^3 logn)

//top down DP: 2100ms 5%, but lee215 & wisdompeak's runtime are good.



//[C] bound on the number of factors/divisors:

//1. larger bound: 2*sqrt(n)

//2. log(n) on average
//2.1. https://terrytao.wordpress.com/2008/09/23/the-divisor-bound/

#define inf_add(a,b) ( (a==INT_MAX || b==INT_MAX)? INT_MAX:(a+b) )

class Solution {
public:
    inline int semi_palin_cost(const string& s, int i, int j, int d){
        int cost = 0;

        for(int t=0;t<d;t++){
            int start = i + t;
            int end = j - (d-1) + t;

            while(start < end){
                if(s[start] != s[end]){
                    cost++;
                }

                start += d;
                end -= d;
            }
        }
        return cost;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        //general factorization.
        //not prime factorization where at most 1 prime factor >= sqrt(n)
        vector<vector<int>> factors(n+1);
        for(int len=2;len<=n;len++){

            for(int f=1;f<=len/2;f++)if(len%f == 0){
                factors[len].push_back(f);
            }
        }


        const int impossible = INT_MAX;
        vector<vector<int>> min_cost(n, vector<int>(n, impossible));
        //length 1 is impossible to be a semi-palindrome.
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){

                int len = j - (i-1);
                for(const int d: factors[len]){
                    min_cost[i][j] = min(
                        min_cost[i][j],
                        semi_palin_cost(s, i, j, d)
                    );
                }
            }


        vector<vector<int>> memo(n, vector<int>(k+1, impossible));
        for(int i=0;i<n;i++){ //TODO
            memo[i][1] = min_cost[0][i];

            for(int part=2;part<=k;part++){
                //length 1 is impossible to be a semi-palindrome.
                if(i - (0-1) <= part) break;

                //length 1 is impossible to be a semi-palindrome.
                for(int j=0;j+1<i;j++){
                    memo[i][part] = min(
                        memo[i][part],
                        inf_add(
                            memo[j][part-1],
                            min_cost[j+1][i]
                        )
                    );
                }
            }
        }

        return memo[n-1][k];
    }
};
