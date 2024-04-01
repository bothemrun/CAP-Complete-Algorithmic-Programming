class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digit;
        int x = n;
        while(x != 0){
            digit.push_back(x%10);
            x /= 10;
        }

        int product = 1;
        for(int x: digit) product *= x;

        int sum = 0;
        for(int x: digit) sum += x;

        return product - sum;
    }
};
