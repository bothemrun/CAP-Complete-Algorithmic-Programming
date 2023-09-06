//m0
//recursion with memo

//like enumerating trees, enumerate all operator as the root of the tree

//O(memo size) * O(each recursion time) = O(n*n) * O(n * possible result^2)
//but the problem says O(different results) <= 1e4
//practically, the judge gives this solution less than 2 ms runtime, beating almost 100% users.

//NOTE: no unary operator

#include<ctype.h>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<string> exp;
    vector<bool> is_operator;

    vector<vector<bool>> done;
    vector<vector<vector<int>>> memo;

    void enum_tree(const int& low, const int& high){

        assert(low <= high);
        if(done[low][high] == true) return;

        if(low == high){
            assert( isdigit( exp[low][0] ) );
            memo[low][high].push_back( stoi( exp[low] ) );
            done[low][high] = true;
            return;
        }

        
        assert(is_operator[low] == false);
        assert(is_operator[high] == false);

        for(int op=low+1;op<=high-1;op++)if(is_operator[op] == true){
            enum_tree(low, op-1);
            enum_tree(op+1, high);

            for(const int& left: memo[low][op-1] )
                for(const int& right: memo[op+1][high] ){
                    int res;
                    if(exp[op] == "+") res = left + right;
                    else if(exp[op] == "-") res = left - right;
                    else if(exp[op] == "*") res = left * right;
                    else assert(false);

                    memo[low][high].push_back(res);
                }
        }

        done[low][high] = true;
    }

    vector<int> diffWaysToCompute(string expression) {
        int expression_size = expression.size();

        int i=0;
        while(i<expression_size){
            if( !isdigit(expression[i]) ){
                exp.push_back( expression.substr(i, 1) );
                i++;
                continue;
            }

            //[i, j]
            int j = i;
            while(j+1<expression_size && isdigit( expression[j+1] ) ) j++;
            exp.push_back( expression.substr(i, j - (i-1) ) );

            i = j+1;
        }


        n = exp.size();

        is_operator.resize(n, false);
        for(int i=0;i<n;i++)if(
            exp[i].size() == 1 && 
            !isdigit( exp[i][0] )
        ) is_operator[i] = true;


        done.resize(n, vector<bool>(n, false));
        memo.resize(n, vector<vector<int>>(n) );
        enum_tree(0, n-1);
        return memo[0][n-1];
    }
};
