#include<ctype.h>
#include<assert.h>
#include<unordered_map>
#include<stack>
class Solution {
public:
    int n;
    unordered_map<int,int> bracket;
    string decode(const string& s, int low, int high){
        assert(0<=low && high<n);

        string res = "";
        //NOTE: for empty string in brackets, just return an empty string.
        while(low <= high){
            if( isalpha(s[low]) ){
                res += s[low++];
                continue;
            }

            if( isdigit(s[low]) ){
                int digit_high = low;
                //NOTE: [low, digit_high) is a number, consider digit_high
                while(digit_high <= high && isdigit(s[digit_high]) ){
                    digit_high++;
                }


                //NOTE: [alpha_low, alpha_high]
                int alpha_low = digit_high + 1;
                
                assert(s[digit_high] == '[');
                assert( bracket.count(digit_high) != 0 );
                int alpha_high = bracket[digit_high] - 1;

                string tmp_res = decode(s, alpha_low, alpha_high);


                int k = stoi( s.substr(low, (digit_high-1) - (low-1) ) );
                for(int i=0;i<k;i++)
                    res += tmp_res;
                

                //NOTE: bypass the right bracket
                low = bracket[digit_high] + 1;
            }else{
                assert(false);
            }
        }

        return res;
    }
    
    string decodeString(string s) {
        n = s.size();
        stack<int> left_idx;
        for(int i=0;i<n;i++){
            if(s[i] == '['){
                left_idx.push(i);
            }else if(s[i] == ']'){
                assert(left_idx.size() != 0);
                bracket[ left_idx.top() ] = i;
                left_idx.pop();
            }
        }


        return decode(s, 0, n-1);
    }
};
