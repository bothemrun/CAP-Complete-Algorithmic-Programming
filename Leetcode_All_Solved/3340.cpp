class Solution {
public:
    bool isBalanced(string num) {
        vector<int> sum(2, 0);
        int n = num.size();
        for(int i=0;i<n;i++){
            sum[i%2] += num[i] - '0';
        }
        return sum[0] == sum[1];
    }
};
