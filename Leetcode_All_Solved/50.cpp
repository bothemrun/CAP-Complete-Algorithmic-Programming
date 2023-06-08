class Solution {
public:
    double divide(const double& x, const long long& n){
        //x>=0, n>=0.  no x==0, n==0
        //divide & conquer
        if(n==0) return 1.0;

        double half = divide(x, n/2);
        half *= half;
        return (n%2==1)? (x*half):half;
    }
    double myPow(double x, int n) {
        if(x==0) return 0;
        
        bool negative = x<0 && n%2==1;
        int sign = (negative)? (-1):1;
        x = (x<0)? (-x):x;

        //NOTE: overflow from -(-2^31) in (-n)
        long long lln = (long long)n;

        return sign * ( 
            (lln<0)? 
            (1.0/divide(x, -lln)): //(1.0/divide(x, -n)):
            divide(x, lln)
        );
    }
};
