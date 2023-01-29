class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digit;
        int x = num;
        while(x != 0){
            digit.push_back(x%10);
            x /= 10;
        }

        for(int i=digit.size()-1;i>=0;i--)if(digit[i] == 6){
            digit[i] = 9;
            
            int ans = 0;
            for(int j=digit.size()-1;j>=0;j--)
                ans = ans*10 + digit[j];
            return ans;
        }

        return num;
    }
};
