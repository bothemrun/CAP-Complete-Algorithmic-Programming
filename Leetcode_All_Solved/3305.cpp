class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
        
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i + (k+5) - 1;j<n;j++){
                int consonant = 0;
                unordered_map<char, bool> has_vow;
                for(int k=i;k<=j;k++){
                    if(vow.find(word[k]) != vow.end()){
                        has_vow[ word[k] ] = true;
                    }else{
                        consonant++;
                    }
                }
                
                bool each_vow = true;
                for(char c: vow)if(has_vow[c] == false){
                    each_vow = false;
                    break;
                }
                if(consonant == k && each_vow){
                    ans++;
                }
            }
        return ans;
    }
};
