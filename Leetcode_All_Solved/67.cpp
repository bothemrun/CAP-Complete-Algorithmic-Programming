#include<string>
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        vector<int> rev_ans;
        for(int i=a.size()-1, j=b.size()-1;i>=0 || j>=0;i--, j--){
            int a_digit = (i>=0)? (a[i]-'0'):0;
            int b_digit = (j>=0)? (b[j]-'0'):0;
            rev_ans.push_back((a_digit+b_digit+carry)%2);
            carry = (a_digit+b_digit+carry)/2;
        }
        while(carry > 0){
            rev_ans.push_back(carry%2);
            carry /= 2;
        }
        string ans = "";
        for(int i=rev_ans.size()-1;i>=0;i--){
            ans += ('0' + rev_ans[i]); //("0"+rev_ans[i]);
        }
        return ans;
    }
};
