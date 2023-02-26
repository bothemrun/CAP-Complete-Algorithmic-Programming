class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> div(n);
        long long sum = 0;
        long long mod = m;
        for(int i=0;i<n;i++){
            sum = ( (10*sum)%mod + (long long)( word[i] - '0' ) )%mod;
            
            if(sum == 0) div[i] = 1;
            else div[i] = 0;
        }
        return div;
    }
};
