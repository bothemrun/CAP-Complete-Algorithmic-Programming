#define mod ((long long)1e9 + 7)

class Solution {
public:
    long long insert_order(const int& n){
        if(n == 1) return 1;

        int k = 2 * (n-1);
        //1+2+3...+(k+1)
        return (
            insert_order(n-1) 
            * (k+1) 
            * (k+2) 
            / 2
        )%mod;
    }
    int countOrders(int n) {
        return (int)insert_order(n);
    }
};
