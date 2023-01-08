class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for(const char& c: word1){
            cnt1[ (int)(c - 'a') ]++;
        }
        for(const char& c: word2){
            cnt2[ (int)(c - 'a') ]++;
        }
        
        int dd1 = 0, dd2 = 0;
        for(int i=0;i<26;i++)if(cnt1[i] != 0){
            dd1++;
        }
        for(int i=0;i<26;i++)if(cnt2[i] != 0){
            dd2++;
        }
        
        for(int i=0;i<26;i++)if(cnt1[i] != 0){
            for(int j=0;j<26;j++)if(cnt2[j] != 0){
                //deeply copied
                vector<int> c1(cnt1);
                vector<int> c2(cnt2);
                int d1 = dd1;
                int d2 = dd2;
                
                c1[i]--;
                if(c1[i] == 0){
                    d1--;
                }
                c2[i]++;
                if(c2[i] == 1){
                    d2++;
                }
                
                c2[j]--;
                if(c2[j] == 0){
                    d2--;
                }
                c1[j]++;
                if(c1[j] == 1){
                    d1++;
                }
                
                if(d1 == d2)return true;
            }
        }
        
        return false;
    }
};
