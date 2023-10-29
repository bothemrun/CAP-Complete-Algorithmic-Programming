//Thinking Process

//[A] the key is multiplication of >= 3 numbers.

//1. the products may consist of >= 3 numbers.
//2. solved by "suffix_products"
//3. this also leads to the conclusion of the choices between partition / choose or not.

class Solution {
public:
    string num;
    long long target;
    int n;
    vector<string> ans;

    void enum_partition(const int& i, const string& cur_ans="", const long long& sum=0, const long long& suffix_products=1){
        if(i == n){
            if(sum == target){
                ans.push_back(cur_ans);
            }
            return;
        }


        //enum partition
        for(int len=1; i + (len-1)<n;len++){
            //no leading 0s, but ok with 0
            if(len >= 2 && num[i] == '0') break;

            string str = num.substr(i, len);
            long long val = stoll(str);

            if(cur_ans.size() == 0){
                //binary operators, so no unary "-"
                enum_partition(
                    i+len,
                    str,
                    val,
                    val
                );
            }else{
                enum_partition(
                    i+len,
                    cur_ans + "+" + str,
                    sum + val,
                    val
                );
                enum_partition(
                    i+len,
                    cur_ans + "-" + str,
                    sum - val,
                    (-val)
                );

                //NOTE: the key is multiplication
                //NOTE: solved by "suffix_products"
                long long new_suffix_products = suffix_products * val;
                enum_partition(
                    i+len,
                    cur_ans + "*" + str,
                    sum - suffix_products + new_suffix_products,
                    new_suffix_products
                );
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        n = num.size();
        this->num = num;
        this->target = target;

        enum_partition(0);
        return ans;
    }
};
