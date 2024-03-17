class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int x: nums){
            int d = 0;
            int m = 0;
            while(x > 0){
                d++;
                m = max(m, x%10);
                x /= 10;
            }
            
            int y = 0;
            for(int i=0;i<d;i++){
                y = y*10 + m;
            }
            
            ans += y;
        }
        
        return ans;
    }
};
