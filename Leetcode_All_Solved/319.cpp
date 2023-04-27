//on-off state == (number of distinct factors)%2.

//for square / non-square numbers, (number of distinct factors)%2 == 1 / 0.

//so answer == how many square numbers <= n
#include<math.h>
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
