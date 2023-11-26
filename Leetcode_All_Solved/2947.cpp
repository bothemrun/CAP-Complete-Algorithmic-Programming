class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        bool is_vowel[256] = {0};
        is_vowel['a'] = true;
        is_vowel['e'] = true;
        is_vowel['i'] = true;
        is_vowel['o'] = true;
        is_vowel['u'] = true;
        
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int vow = 0;
            int con = 0;
            for(int j=i;j<n;j++){
                if( is_vowel[ s[j] ] == true){
                    vow++;
                }else{
                    con++;
                }
                
                if(vow == con && (vow * con)%k == 0 ){
                    ans++;
                }
            }
        }
        return ans;
    }
};
