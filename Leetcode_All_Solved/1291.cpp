class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int low_digit = to_string(low).size();
        int high_digit = to_string(high).size();
        for(int digit=low_digit;digit<=high_digit;digit++){
            for(long long start=1;start<=8;start++){
                if(start + (digit-1) > 9) break;

                long long x = 0;
                for(long long d=0;d<digit;d++){
                    x = x*10LL + (start+d);
                }

                if(low<=x && x<=high)
                    ans.push_back(x);
            }
        }

        return ans;
    }
};
