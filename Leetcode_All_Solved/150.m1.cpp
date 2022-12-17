//m1
#include<stack>
class Solution {
public:
    stack<long long> operand;
    inline long long pop2(){
        long long x = operand.top();
        operand.pop();
        return x;
    }
    int evalRPN(vector<string>& tokens) {
        
        for(const string& token:tokens){
            if(token == "+"){
                long long a = pop2();
                long long b = pop2();
                operand.push( b + a );
            }else if(token == "-"){
                long long a = pop2();
                long long b = pop2();
                operand.push( b -a );
            }else if(token == "*"){
                long long a = pop2();
                long long b = pop2();
                operand.push( b * a );
            }else if(token == "/"){
                long long a = pop2();
                long long b = pop2();
                operand.push( b / a );
            }else{
                operand.push( stoll(token) );
            }
        }
        return operand.top();
    }
};
