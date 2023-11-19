class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        vector<long long> zero;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                zero.push_back(i);
            }
        }
        
        long long ans = 0;
        for(long long i=0;i<(long long)zero.size();i++){
            ans += zero[i] - i;
        }
        return ans;
    }
};
