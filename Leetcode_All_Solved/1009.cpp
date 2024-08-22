class Solution {
public:
    int bitwiseComplement(int n) {
        //edge case
        if(n==0) return 1;
        
        vector<int> bits;
        while(n != 0){
            bits.push_back(n % 2);
            n /= 2;
        }

        reverse(bits.begin(), bits.end());
        int ans = 0;
        for(const int& b: bits)
            ans = ans*2 + (b^1);
        return ans;
    }
};
