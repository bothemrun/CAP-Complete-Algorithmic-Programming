#include <stack>
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        // 1. all rounds
        for(vector<string>::iterator it = ops.begin();it != ops.end();it++){
            if(*it == "+"){
                // no bound check
                int last1 = scores.top();
                scores.pop();
                int last2 = scores.top();
                scores.push(last1);
                scores.push( last1 + last2 );
            }else if(*it == "C"){
                // include the case of empty stack 
                scores.pop();
            }else if(*it == "D"){
                scores.push( scores.top() * 2 );
            }else {
                // integer
                // string to int : int stoi(string str)
                scores.push( stoi(*it) );
            }//else
        }//for it
        
        // 2. final scores
        int ans = 0;
        while(scores.empty() == false){ 
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
};
