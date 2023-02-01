class Solution {
public:
    int gcd(int a, int b){
        if(a < b)return gcd(b, a);
        if(b == 0)return a;
        return gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        
        int gcd_len = gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_len);
    }
};
