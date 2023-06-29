//dual: 00, 11, 69, 96, 88
//self: 0, 1, 8
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    unordered_map<char,char> two = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'9', '6'},
        {'8', '8'}
    };
    vector<char> one = {'0', '1', '8'};
    
    vector<string> ans;
    string ans1 = "";
    int n;
    void backtrack(const int& i, const int& end){
        if(!(i<=end)){
            if(n%2 == 1){
                for(const char& one_end: one)
                    ans.push_back(ans1 + one_end);
            }else ans.push_back(ans1);
            return;
        }

        for(const auto& [key, val]: two){
            //NOTE: edge: no leading 0, if number != 0
            if(i==0 && key == '0') continue;

            ans1 += key;
            backtrack(i+1, end);

            int ans1_size = ans1.size();
            ans1.erase(ans1.begin() + ans1_size-1);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        this->n = n;
        //4/2=2, 1.  5/2=2, 1. 1/2=0, -1.
        int end = n/2 - 1;//inclusive. ok for n==1
        backtrack(0, end);


        for(string& ans1: ans){
            for(int i=end;i>=0;i--)
                ans1 += two[ ans1[i] ];
        }
        return ans;
    }
};
