class Solution {
public:
    int findComplement(int num) {
        vector<int> bits;
        while(num != 0){
            bits.push_back(num % 2);
            num /= 2;
        }

        reverse(bits.begin(), bits.end());
        int ans = 0;
        for(const int& b: bits)
            ans = ans*2 + (b^1);
        return ans;
    }
};
