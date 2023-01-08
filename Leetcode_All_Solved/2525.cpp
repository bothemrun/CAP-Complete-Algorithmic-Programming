#define bulky_dim ((int)(1e4))
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = (long long)length * (long long)width * (long long)height;
        bool bulky = ( length >= bulky_dim || width >= bulky_dim || height >= bulky_dim ) || volume >= ((long long)(1e9));
        
        bool heavy = mass >= 100;
        
        if(bulky && heavy) return "Both";
        else if(!bulky && !heavy) return "Neither";
        else if(bulky) return "Bulky";
        else return "Heavy";
    }
};
