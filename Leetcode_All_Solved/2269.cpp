class Solution {
public:
    void make_digits(int num, vector<int>& digits){
        while(num != 0){
            digits.push_back(num%10);
            num /= 10;
        }
    }
    int divisorSubstrings(int num, int k) {
        vector<int> digits;
        make_digits(num, digits);
        
        if(digits.size() < k)return 0;
        int win = 0;
        for(int i=0;i<k;i++){
            win *= 10;
            win += digits.at(digits.size()-1-i);
        }
        
        int ans = 0;
        if(win != 0 && num%win == 0)ans++;
        
        int pow_k = 1;
        for(int i=0;i<k-1;i++) pow_k *= 10;
        
        for(int win_head = digits.size() - k - 1;win_head >= 0;win_head--){
            int pre_win_tail = win_head + k;
            win -= digits.at(pre_win_tail) * pow_k;
            win *= 10;
            win += digits.at(win_head);
            
            if(win != 0 && num%win == 0)ans++;
        }
        
        return ans;
    }
};
