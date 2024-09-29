class Solution {
public:
    char kthCharacter(int k) {
        string w = "a";
        while(w.size() < k){
            string app = "";
            for(char c: w){
                app += ( (c-'a') + 1 )%26 + 'a';
            }
            w += app;
        }
        
        return w[k-1];
    }
};
