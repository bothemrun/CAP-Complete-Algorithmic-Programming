#include<stack>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(const int& a:asteroids){
            if(s.size() == 0 || !(s.top() > 0 && a < 0) ){
                s.push(a);
                continue;
            }
            //a < 0 below
            while(s.size() > 0 && s.top() > 0){
                if(s.top() > (-a) )break;
                else if(s.top() < (-a) ){
                    //NOTE: only case for considering push(a)
                    s.pop();
                    
                    if(s.size() == 0){
                        s.push(a);
                        break;
                    }
                    
                    if(s.top() < 0){
                        s.push(a);
                        break;
                    }else if(s.top() > (-a) ){
                        break;
                    }
                }else{
                    s.pop();
                    break;
                }
            }//while
        }
        
        vector<int> rev;
        while(s.size() > 0){
            rev.push_back(s.top());
            s.pop();
        }
        vector<int> ans;
        for(int i=rev.size()-1;i>=0;i--)ans.push_back(rev[i]);
        return ans;
    }
};
