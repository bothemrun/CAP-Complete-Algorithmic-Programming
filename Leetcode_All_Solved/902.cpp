//annoying edge cases

//so it's crucial to organize them into different cases to handle.

//don't mix them together by trying to make a universal function that returns the answer at once.

class Solution {
public:
    vector<char> digits;
    unordered_set<char> digits_s;

    //must consider connectivity with upper digits, since it's recursion.
    int use_all_digits(const string& s){
        //tricky edge cases for s.size() == 0!!
        if(s.size() == 1){
            int cnt = 0;
            for(char d: digits) cnt += d <= s[0];
            return cnt;
        }

        //msd diff
        int sub_cnt = 0;//can't use 0 as msd, since we have to use all digits
        for(char d: digits) sub_cnt += d < s[0];
        int msd_diff = sub_cnt * (int)pow( (int)digits.size(), (int)s.size()-1 );

        //msd same
        int msd_same = 0;
        if(digits_s.count(s[0]) != 0)
            msd_same = use_all_digits(s.substr(1));

        return msd_diff + msd_same;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for(string d: digits){
            this->digits.push_back(d[0]);
            digits_s.insert(d[0]);
        }

        //not using all digits
        int k = to_string(n).size();
        int not_use_all_d = 0;
        for(int d=1;d<=k-1;d++)
            not_use_all_d += (int)pow( (int)digits.size(), d );
        
        //use all digits
        int use_all_d = use_all_digits(to_string(n));

        return not_use_all_d + use_all_d;
    }
};
