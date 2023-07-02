//NOTE: no subtraction, just the negative sign on the next number,
//NOTE: and all operations in the stack are addition.

//NOTE: of course, we can use large negative numbers to denote symbols.
//NOTE: but for a general case, these negative numbers will be used.
//NOTE: and string number addition is costly.
//NOTE: so we use a pair
//use pair.int if pair.char == '', vice versa.

#define Pic pair<int, char>
#define int_mark '$'
#define char_mark INT_MAX
#include<limits.h>
#include<utility>
#include<stack>
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
    inline void push_num(stack<Pic>& sta, const int& num){
        //NOTE: handles the negative sign in the stack.

        if(sta.size() && sta.top().second == '-'){
            //NOTE: pitfall
            sta.pop();

            sta.push( Pic(-num, int_mark) );
        }else sta.push( Pic(num, int_mark) );
    }
    int calculate(string s) {
        int n = s.size();

        stack<Pic> sta;
        int i = 0;
        while(i<n){
            const char& c = s[i];

            if(isdigit(c)){
                //number window
                int left = i;
                while(i+1<n && isdigit( s[i+1] ) ) i++;
                int num = stoi( s.substr(left, i - (left-1) ) );
                push_num(sta, num);

            }else if(c=='('){
                sta.push(Pic(char_mark, '('));
            }else if(c==')'){

                int sum = 0;
                assert(sta.size());
                while(sta.top().second != '('){
                    assert(sta.top().second == int_mark);
                    sum += sta.top().first;
                    sta.pop();

                    assert(sta.size());
                }

                //NOTE: pitfall
                assert(sta.top().second == '(');
                sta.pop();

                push_num(sta, sum);

            }else if(c=='-'){
                sta.push(Pic(char_mark, '-'));
            }//else: +, space: do nothing


            i++;
        }

        //NOTE: pitfall: finally pop all stack
        int res = 0;
        while(sta.size()){
            assert(sta.top().second == int_mark);
            res += sta.top().first;
            sta.pop();
        }
        return res;
    }
};
