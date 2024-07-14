//m0
//O(n^2)

//[A] to avoid repeated codes of depleting all chars of the same type (digits / lowercase letters):

//1. passing function as a parameter
//2. for C++ built-in functions, use a wrapper.

#define tsi tuple<string, int>
#include<ctype.h>
#include<functional>

inline int isdigit_(int c){return isdigit(c);}
inline int isalpha_lower(int c){return isalpha(c) && islower(c);}

class Solution {
public:
    int n;
    /*
    error: reference to non-static member function must be called
    inline int isdigit_(int c){return isdigit(c);}
    inline int isalpha_(int c){return isalpha(c);}
    */
    inline string conti_same_type(const string& s, const int i, function<int(int)> istype){
        if(!(i<n)) return "";
        if(!istype(s[i])) return "";

        int j = i;
        while(j+1<n && istype(s[j+1])){
            j++;
        }
        return s.substr(i, j - (i-1) );
    }

    string countOfAtoms(string formula) {
        this->n = formula.size();

        const tsi left_paren = tsi("(", -2);
        const tsi null = tsi("$", -3);
        vector<tsi> sta;

        int i=0;
        while(i<n){
            if( isalpha(formula[i]) ){
                //atom letters
                string atom = formula[i] + conti_same_type(formula, i + 1, isalpha_lower);

                //digits behind
                string digit = conti_same_type(formula, i + (int)atom.size(), isdigit_);
                int atom_cnt = (digit=="")? 1:stoi(digit);

                sta.push_back(tsi(atom, atom_cnt));

                //update
                i += (int)atom.size() + (int)digit.size();
            }else if(formula[i] == '('){
                sta.push_back(left_paren);

                //update
                i++;
            }else{
                //')'
                //digits behind
                //may be another ')' '(' out of bound
                string digit = conti_same_type(formula, i + 1, isdigit_);
                int paren_cnt = (digit=="")? 1:stoi(digit);

                //O(n) dump from stack
                assert(sta.size());
                //can also use a tmp vector & pop & push again.
                int j;
                for(j=(int)sta.size()-1;j>=0;j--){
                    if(sta[j] == left_paren){
                        sta[j] = null;
                        break;
                    }

                    auto& [atom, atom_cnt] = sta[j];
                    //to prevent null
                    if(isalpha(atom[0])){
                        atom_cnt *= paren_cnt;
                    }
                }
                assert(j>=0 && sta[j] == null);

                //update
                i += (int)digit.size() + 1;
            }

            //no isalpha(formula[i])
            //since digits always follow atom letters or right parenthesis.
        }//while i<n

        map<string, int> atom2cnt;
        for(const auto& [atom, cnt]: sta)if(isalpha(atom[0])){
            //to avoid null
            atom2cnt[atom] += cnt;
        }

        string ans = "";
        for(const auto& [atom, cnt]: atom2cnt){
            ans += atom + (
                (cnt==1)? "":to_string(cnt)
            );
        }
        return ans;
    }
};
