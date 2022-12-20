class Solution {
public:
    int minSteps(int n) {
        int cnt = 0;
        int prime = 2;
        while(n != 1){
            while(n%prime == 0){
                n /= prime;
                cnt += prime;
            }

            prime++;
        }
        return cnt;
    }
};
