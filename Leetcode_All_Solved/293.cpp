#define curst currentState

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        int n = curst.size();
        int i=0;
        while(i+1<n){
            if(curst[i+1] == '-'){
                i += 2;
            }else if(curst[i] == '-'){
                i++;
            }else{
                //copy
                string tmp = curst;
                tmp[i] = '-';
                tmp[i+1] = '-';

                ans.push_back(tmp);
                i++;
            }
        }

        return ans;
    }
};
