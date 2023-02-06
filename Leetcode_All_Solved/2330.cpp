class Solution {
public:
    bool palindrome(const string& s, int low, int high, int k){
        if(low >= high)return true; /*{
            if(k == 2)return s.size() >= 2;
            else return true;//k<=1
        }*/
        
        if(s[low] == s[high])
            return palindrome(s, low+1, high-1, k);
        if(k == 0)return false;
        return palindrome(s, low+1, high-1, k-1);
    }
    bool makePalindrome(string s) {
        int n  = s.size();
        return palindrome(s, 0, n-1, 2);
    }
};
