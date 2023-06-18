#define test 0 //1 0
#include<unordered_map>

#if test == 0
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
#endif

class Solution {
public:
    unordered_map<int, string> sym = {
        {1, "I"}, {4, "IV"}, {5, "V"},
        {9, "IX"}, 
        
        {10, "X"},
        {40, "XL"}, {50, "L"},
        {90, "XC"}, 
        
        {100, "C"},
        {400, "CD"}, {500, "D"},
        {900, "CM"}, 
        
        {1000, "M"},

        {0, ""} //NOTE: empty for 0
    };

    string intToRoman(int num) {
        for(int ten=1;ten<=1000;ten*=10){

            for(int digit=2;digit<=3;digit++){
                sym[digit*ten] = sym[1*ten];

                for(int i=0;i<(digit-1);i++)
                    sym[digit*ten] += sym[1*ten];
            }

            if(ten == 1000) break;

            for(int digit=6;digit<=8;digit++){
                sym[digit*ten] = sym[5*ten];

                for(int i=0;i<(digit-5);i++)
                    sym[digit*ten] += sym[1*ten];
            }
        }

        #if test == 1
        for(auto [key, val]: sym) cout<<key<<" "<<val<<endl;
        #endif

        string ans = "";
        for(int ten=1000;ten>=1;ten/=10){
            ans += sym[ (num/ten) *ten ];
            num = num%ten;
        }
        return ans;
    }
};
