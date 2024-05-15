class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size();
        if(k==1){
            int i=0;
            while(i+1<n && s[i+1] != ' '){
                i++;
            }

            return s.substr(0, i+1);
        }

        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                k--;

                if(k == 1){
                    i++;
                    while(i+1<n && s[i+1] != ' '){
                        i++;
                    }

                    return s.substr(0, i+1);
                }
            }
        }

        assert(false);
        return s;
    }
};
