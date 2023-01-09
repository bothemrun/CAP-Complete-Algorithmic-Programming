#include<algorithm>
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();

        int max_len_sum = 0;
        int len_sum = 0;
        vector<int> len;
        int i = 0;
        while(i < n){
            //1. count tabs
            int nontab_low = i;
            while(nontab_low < n && input[nontab_low] == '\t')
                nontab_low++;
            
            int tab_cnt = (nontab_low-1) - (i-1);//ok for 0 tab_cnt

            //2. reach until new line char or end of input
            int newline_end_low = nontab_low;
            while(newline_end_low < n && input[newline_end_low] != '\n')
                newline_end_low++;
            //ok for last file or directory

            //3. pop until tab_cnt == len.size()
            while(len.size() > tab_cnt){
                len_sum -= len.back();
                len.pop_back();
            }

            //4. then push this
            len.push_back( (newline_end_low - 1) - (nontab_low - 1) );
            len_sum += (newline_end_low - 1) - (nontab_low - 1);

            //5. check if it's a file
            for(int k=nontab_low;k<newline_end_low;k++){
                //6. don't forget the slash
                if(input[k] == '.'){
                    max_len_sum = max(
                        max_len_sum,
                        len_sum + (int)(len.size() - 1)
                    );
                    break;
                }
            }

            //7. update
            i = newline_end_low + 1;
        }

        return max_len_sum;
    }
};
