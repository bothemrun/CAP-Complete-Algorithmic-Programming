class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        while(k != 0 || n != 0){
            if(k%2==1 && n%2==0){
                return (-1);
            }else if(k%2==0 && n%2==1){
                ans++;
            }

            k >>= 1;
            n >>= 1;
        }
        return ans;
    }
};
