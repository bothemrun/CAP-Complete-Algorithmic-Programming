class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int b=2;b<=n-2;b++){
            vector<int> repre;
            int x = n;
            while(x > 0){
                repre.push_back(x%b);
                x /= b;
            }

            //i<=size-1-i
            int size = repre.size();
            for(int i=0;i<=( size-1 - i );i++)if(repre[i] != repre[size-1 - i])
                return false;
        }

        return true;
    }
};
