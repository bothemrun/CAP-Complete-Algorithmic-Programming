//m1
//O(n) recursion
class Solution {
public:
    int winner0based(const int& n, const int& k){
        if(n == 1)return 0;
        return ( winner0based(n-1, k) + k )%n;
    }
    int findTheWinner(int n, int k) {
        return winner0based(n, k) + 1;//1-based
    }
};
