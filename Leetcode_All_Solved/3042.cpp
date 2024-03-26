//m0
//brute force
//O(n^2 * L) = O(50^2 * 10) = 2e4

class Solution {
public:
    inline bool pref_suf(const string& a, const string& b){
        int asize = a.size();
        int bsize = b.size();
        if(asize > bsize) return false;

        for(int i=0;i<asize;i++)if(a[i] != b[i]) return false;

        for(int i=0;i<asize;i++)if(a[i] != b[ (bsize-1) - (asize-1) + i ] )
            return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans += pref_suf(words[i], words[j]);
        
        return ans;
    }
};
