class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        int i = 0;
        while(n > 0){
            if(n%2 == 1){
                if(i%2 == 0)even++;
                else odd++;
            }
            
            n /= 2;
            i++;
        }
        return vector<int>({even, odd});
    }
};
