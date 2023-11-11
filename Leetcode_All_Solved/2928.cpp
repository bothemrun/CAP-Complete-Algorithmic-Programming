class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for(int i=0;i<=limit;i++)
            for(int j=0;j<=limit;j++){
                int k = n - i - j;
                if(!( k <= limit && k>=0 )) continue;
                
                ans++;
            }
        return ans;
    }
};
