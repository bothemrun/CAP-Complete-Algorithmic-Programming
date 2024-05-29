class Solution {
public:
    int numSteps(string s) {
        s = "0" + s;

        int n = s.size();
        int back_i = n-1;
        int step = 0;
        while(!(
            (back_i==1 && s.substr(0, 2) == "01") ||
            (back_i==0)
        )){
            step++;

            if(s[back_i] == '0') back_i--;
            else{
                int i = back_i;
                while(i>=0 && s[i] == '1'){
                    s[i--] = '0';
                }

                assert(i>=0);
                s[i] = '1';
            }
        }

        return step;
    }
};
