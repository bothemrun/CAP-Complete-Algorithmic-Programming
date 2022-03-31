#include<stack>
#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> operand;
        for(const string& s:tokens){
            if(s == "+"){
                int a = operand.top(); operand.pop();
                int b = operand.top(); operand.pop();
                operand.push(a+b);
            }
            else if(s == "-"){
                int a = operand.top(); operand.pop();
                int b = operand.top(); operand.pop();
                operand.push(b-a);
            }
            else if(s == "*"){
                int a = operand.top(); operand.pop();
                int b = operand.top(); operand.pop();
                operand.push(a*b);
            }
            else if(s == "/"){
                int a = operand.top(); operand.pop();
                int b = operand.top(); operand.pop();
                operand.push(b/a);
            }
            else operand.push( stoi(s) );
        }
        
        return operand.top();
    }
};
