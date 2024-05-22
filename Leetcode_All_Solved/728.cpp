class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int x=left;x<=right;x++){
            int x2 = x;
            bool div = true;

            while(x2 != 0){
                int digit = x2%10;

                if(digit == 0){
                    div = false;
                    break;
                }

                if(!( x % digit == 0 )){
                    div = false;
                    break;
                }

                x2 /= 10;
            }

            if(div) ans.push_back(x);
        }

        return ans;
    }
};
