class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming = x ^ y;
        int hamming_dist = 0;
        while(hamming > 0){
            if(hamming%2 == 1)hamming_dist++;
            hamming /= 2;
        }
        return hamming_dist;
    }
};
