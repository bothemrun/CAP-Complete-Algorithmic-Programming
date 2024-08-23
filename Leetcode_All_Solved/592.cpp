//assume the middle results of doing fractions 1 by 1 can fit in long long.

class Solution {
public:
    inline long long gcd(long long a, long long b){
        if(!(a >= b)) return gcd(b, a);

        if(b==0) return a;
        return gcd(b, a%b);
    }
    string fractionAddition(string expression) {
        int n = expression.size();

        vector<long long> numerator, denominator;

        function<int(int)> all_digit = [n, &expression](int i){
            int j = i;
            while(j+1<n && isdigit( expression[j+1] )){
                j++;
            }
            return j;
        };

        int i=0;
        while(i<n){
            long long sign = 1;
            if(!(isdigit( expression[i] ))){
                if(expression[i] == '+') sign = 1;
                else if(expression[i] == '-') sign = (-1);
                else assert(false);

                assert(++i<n);
            }

            int nu_j = all_digit(i);
            numerator.push_back( sign * stoll( expression.substr(i, nu_j - (i-1) ) ) );

            assert(nu_j+2<n && expression[nu_j+1]=='/');
            i = nu_j+2;

            int de_j = all_digit(i);
            denominator.push_back( stoll( expression.substr(i, de_j - (i-1) ) ) );

            //update
            i = de_j+1;
        }


        long long nu = 0;
        long long de = 1;
        for(int k=0;k<(int)numerator.size();k++){
            long long nu1 = numerator[k];
            long long de1 = denominator[k];

            long long nu2 = nu * de1 + de * nu1;
            long long de2 = de * de1;

            long long g = gcd(abs(nu2), de2);

            nu = nu2 / g;
            de = de2 / g;
        }

        return to_string(nu) + "/" + to_string(de);
    }
};
