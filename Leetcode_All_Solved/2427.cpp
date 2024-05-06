class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for(int f=1;f<=min(a, b);f++)
            if( a%f==0 && b%f==0 )
                ans++;
        return ans;
    }
};
