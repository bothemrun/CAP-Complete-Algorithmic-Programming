//Thinking Process:

//[A] Computing The Opposite Is Easier
//1. compute the results without "leet".

//[B] formula for the union of 3 sets
//1. Principle of Inclusion-Exclusion
//2. union(A || B || C) = A + B + C - AB - BC - CA + ABC

//3. let s == l^a e^b t^c ......
//4. union of (a==0 || b <= 1 || c==0)


//[C] Computer Power
//1. why can't we use C++ pow() ?
//2. it returns an approximate floating number when the result is large,
//3. so turning it into an integer loses accuracy.
//4. so we need to implement power with mod.

class Solution {
public:
    const long long mod = (long long)1e9 + 7LL;

    inline long long pmod(long long a, long long b){
        long long res = 1LL;
        for(long long i=0;i<b;i++){
            res *= a;
            res %= mod;
        }
        return res;
    }

    int stringCount(int input_n) {
        long long n = input_n;
        const long long alpha = 26;

        long long full = pmod(alpha, n);


        //single
        long long single = 
            (
                pmod(alpha-1, n)*3LL
            )%mod + 
            ( 
                pmod(alpha-1, n-1)*n 
            )%mod;
        single %= mod;

        //triple
        long long triple = 
                pmod(alpha-3, n) + 
            ( 
                pmod(alpha-3, n-1) * n 
            )%mod;
        triple %= mod;

        //double
        long long doubl = 
            ( 
                pmod(alpha-2, n)*3LL 
            )%mod + 
            ( 
                pmod(alpha-2, n-1)*n * 2LL 
            )%mod;
        doubl %= mod;

        long long uni = (single - doubl + triple)%mod;

        return ( (full - uni)%mod + mod )%mod;
    }
};
