//"3+2/-2" invalid input.

#include<stack>
#include<ctype.h>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    inline int remove_space(const string& s, int i){
        assert(i<n);
        while(i<n && isspace( s[i] ) ) i++;
        return i;
    }
    inline int digit_window(const string& s, const int& i){
        assert(i<n && isdigit( s[i] ) );

        //[i, j]
        int j = i;
        while(j+1<n && isdigit( s[j+1] )) j++;
        return j;
    }

    int calculate(string s) {
        n = s.size();

        stack<int> sta;

        int i=0;
        while(i<n){
            const char& c = s[i];

            if(isdigit(c)){
                int start = i;
                int end = digit_window(s, start);
                sta.push( stoi( s.substr(start, end - (start-1) ) ) );

                i = end + 1;
            }else if(c == '-'){
                int start = remove_space(s, i + 1);

                int end = digit_window(s, start);
                sta.push( -stoi( s.substr(start, end - (start-1) ) ) );

                i = end + 1;
            }else if(c == '*' || c == '/'){
                
                int start = remove_space(s, i + 1);

                //NOTE: "3+2/-2" invalid input.
                assert(start<n && isdigit( s[start] ) );

                int end = digit_window(s, start);
                int y = stoi( s.substr(start, end - (start-1) ) );

                assert(sta.size());
                int x = sta.top();
                sta.pop();

                if(c == '*'){
                    sta.push( x * y );
                }else{
                    assert(y != 0);
                    sta.push( x / y );
                }

                i = end + 1;
            }else{
                //c == '+' or space, skip,
                //NOTE: but i++ !!!
                i++;
            }
        }


        int res = 0;
        while(sta.size()){
            res += sta.top();
            sta.pop();
        }

        return res;
    }
};
