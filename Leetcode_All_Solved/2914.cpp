static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();

        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && s[i] == s[j+1]){
                j++;
            }

            int len = j - (i-1);
            if(len%2==1){
                ans++;
                assert(j+1<n);
                i = j+2;
            }else{
                i = j+1;
            }
        }
        return ans;
    }
};
