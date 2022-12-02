class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //NOTE: xor property
        int product = 0;//NOTE: identity of xor
        for(int num: nums) product ^= num;
        return product;
    }
};
