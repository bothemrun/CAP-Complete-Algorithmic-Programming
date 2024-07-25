//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int ans = 0;
        int wait = 0;
        int i=0;
        while(i<n){
            while(i<n && s[i] == '0'){
                i++;
            }

            int j = i;
            while(j+1<n && s[j+1] == '1'){
                j++;
            }

            if(!(j<n)) break;

            ans += wait;
            wait += j - (i-1);

            i = j+1;
        }
        //trap
        if(s.back() == '0'){
            ans += wait;
        }

        return ans;
    }
};
