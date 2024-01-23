//O(2^n) = 6e4 backtracking
#include<algorithm>

class Solution {
public:
    vector<int> bits;
    int n;
    int max_len = 0;
    void choose_or_not(const int& i, const int& mask=0, const int& len=0){
        if(i==n){
            max_len = max(max_len, len);
            return;
        }

        //skip
        choose_or_not(i+1, mask, len);

        //choose
        if((mask & bits[i]) == 0)
            choose_or_not(i+1, mask | bits[i], len + __builtin_popcount(bits[i]) );
    }
    
    int maxLength(vector<string>& arr) {
        for(const string& s: arr){
            int bit = 0;
            bool uni = true;
            for(char c: s){
                int mask = (1 << (c - 'a'));
                if((mask & bit) != 0){
                    uni = false;
                    break;
                }

                bit |= mask;
            }

            if(uni == true){
                bits.push_back(bit);
            }
        }


        this->n = bits.size();
        choose_or_not(0);
        return max_len;
    }
};
