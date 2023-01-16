#include<algorithm>
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        num.front() += k;
        int i = 0;
        while(num[i] >= 10){
            if(i+1 == num.size())
                num.push_back(num[i]/10);
            else num[i+1] += num[i]/10;

            num[i] %= 10;
            i++;
        }

        reverse(num.begin(), num.end());
        return num;
    }
};
