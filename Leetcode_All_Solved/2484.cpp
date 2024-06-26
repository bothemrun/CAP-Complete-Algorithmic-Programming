//m0

//[A] all states, thinkg process

//0. typical palindrom shrink dp in O(n^2) --> TLE

//1. (choose or skip at i, first, second, third, fourth, fifth)

//2. (choose or skip at i, first, second, third, len)

//3. (choose or skip at i, first, second, len)

//4. from O(n * 10^5), O(n * 10^3 * 5) to O(n * 10^2 * 5) = O(1e4 * 5e2) = O(5e6)

#define mod ((int)1e9 + 7)

#define alphabet (10+1)
#define no_char (alphabet-1)
#define palin_len 5

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<vector<vector<int>>>> memo;
    int enum_states(const string& s, int i, int first, int second, int len){

        //finished 1.
        //this before if(i<0)
        if(len==palin_len) return 1;

        //still not finished 1.
        if(i<0) return 0;

        if(memo[i][first][second][len] != notyet) return memo[i][first][second][len];

        //1. skip
        int skip = enum_states(s, i-1, first, second, len);

        //2. choose to lengths 1~5
        int choose = 0;
        if(len==0){
            choose = enum_states(s, i-1, s[i]-'0', no_char, 1);
        }else if(len==1){
            choose = enum_states(s, i-1, first, s[i]-'0', 2);
        }else if(len==2){
            //the middle char
            choose = enum_states(s, i-1, first, second, 3);
        }else if(len==3 && s[i]-'0' == second){
            choose = enum_states(s, i-1, first, second, 4);   
        }else if(len==4 && s[i]-'0' == first){
            choose = enum_states(s, i-1, first, second, 5);
        }

        return memo[i][first][second][len] = (skip + choose)%mod;
    }

    int countPalindromes(string s) {
        this->n = s.size();
        memo.resize(n, vector<vector<vector<int>>>(alphabet, vector<vector<int>>(alphabet, vector<int>(palin_len, notyet) ) ) );

        return enum_states(s, n-1, no_char, no_char, 0);
    }
};
