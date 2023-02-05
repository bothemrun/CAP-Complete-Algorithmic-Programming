class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int i = 0;
        while(i < m){
            while(i < m && flowerbed[i] == 1){
                i++;
            }
            if(i == m)break;

            int low = i;
            while(i < m && flowerbed[i] == 0){
                i++;
            }
            int high = i-1;

            int zero = high - (low-1);
            
            //zero -= 2;
            //NOTE: edge case: boundary
            if(low != 0) zero--;
            if(high != m-1) zero--;

            if(zero > 0) n -= (zero+1)/2;
        }

        return n <= 0;
    }
};
