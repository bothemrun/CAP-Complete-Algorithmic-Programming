//m0

//[A] nested? yes

//0. aaaaabbbbbcaaaaabbbbbc as "2[5[a]5[b]c]"
//1. can use the original s to check if a subtring can be encoded.
//2. then use results of repeated segments.


//[B] so [A] implies overlapping subproblems & optimal substructure.


//[C] strategies for dp(i, j)
//1. original s[i, j]
//2. O(n^2) try all lengths of repeated segments
//3. cut into several parts --> in practice, cut into 2 parts.

//O(n^4)

class Solution {
public:
    const string notyet = "$";
    vector<vector<string>> memo;
    int n;

    inline string try_repeat(const string& s, int i, int j){
        int subs_n = j - (i-1);
        string subs = s.substr(i, subs_n);

        string ret = subs;
        //general factorization (not prime factorization)
        for(int len=1;len<=subs_n/2;len++)if(subs_n % len == 0){
            bool is_repeat = true;
            for(int start=len;start<subs_n;start += len){
                if( subs.substr(0, len) != subs.substr(start, len) ){
                    is_repeat = false;
                    break;
                }
            }

            if(is_repeat==true){
                string trial =
                    to_string(subs_n / len)
                    + "["
                    + shrink3strategies(s, i, i + (len-1) )
                    + "]";
                
                
                if(trial.size() <= ret.size()){
                    ret = trial;
                }
            }
        }
        return ret;
    }

    string shrink3strategies(const string& s, int i, int j){
        if(i>j) return "";

        //pruning
        int len = j - (i-1);
        if(len <= 3) return s.substr(i, len);

        if(memo[i][j] != notyet) return memo[i][j];

        //strategy 1
        string ret = s.substr(i, len);

        //strategy 2
        for(int k=i;k+1<=j;k++){
            string cut = shrink3strategies(s, i, k) + shrink3strategies(s, k+1, j);

            if(cut.size() <= ret.size()){
                ret = cut;
            }
        }

        //strategy 3
        string repeat = try_repeat(s, i, j);
        if(repeat.size() <= ret.size()){
            ret = repeat;
        }

        return memo[i][j] = ret;
    }

    string encode(string s) {
        this->n = s.size();
        memo.resize(n, vector<string>(n, notyet));

        return shrink3strategies(s, 0, n-1);
    }
};
