class Solution {
public:
    bool palindrome(const string& s, int low, int high, int k){
        if(low >= high)return true;

        if(s[low] == s[high])
            return palindrome(s, low+1, high-1, k);
        
        if(k == 0)return false;
        return palindrome(s, low+1, high, k-1) ||
        palindrome(s, low, high-1, k-1);
    }
    bool validPalindrome(string s) {
        int n = s.size();
        return palindrome(s, 0, n-1, 1);
    }
};
