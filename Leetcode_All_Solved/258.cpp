//m0
//digital root congruence formula
//b == 1 mod(b-1)
//b^k == 1^k == 1 mod(b-1)
//so n == (d_0 * 1 + d_1 * b + ... d_k * b*k) == d_0 + d_1 + ... d_k mod(b-1)
//so the above iteration can be applied for many times,
//so digital root of n = n%(b-1)

//but edge cases:
//1. if n == (b-1)*m, then the above iteration can only reach down to (b-1), not 0, so its digital root is (b-1).

//2. another n satisfying n == (b-1)*z is n = 0, whose digital root is 0, not (b-1).

//from wikipedia of digital root  & DBabichev solution explanation (other solutions have bad explanation or lack of proof).
class Solution {
public:
    int addDigits(int num) {
        const int b = 10;
        if(num == 0) return 0;
        else if(num%(b-1)==0) return (b-1);//never reach down to 0
        else return num%(b-1);
    }
};
