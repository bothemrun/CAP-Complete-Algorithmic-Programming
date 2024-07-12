//[Greedy Proof]

//1. all the solutions didn't give a convincing greedy proof.


//[A] proof by contradiction

//1. assume gain(ab) >= gain(ba)
//2. the greedy strategy is to remove ab first recursively.

//3. assume there exist an optimal sol that removing ba before some removal of ab.


//[B] enum *ba* --> remove inner ba first:

//also need to prove 2 choices make the remainders the same.

/*
1. *a ba a* --> inner ba < left ab --> both cases remain aa
2. *b ba b* --> inner ba < right ab --> both cases remain bb
3. *a ba b* --> inner ba then outer ab < ab ab --> both choices remain null
4. *b ba b* --> inner bb < right ab --> both cases remain bb

5.    ba --> trivial
6.    ba a* --> trivial
7.    ba b* --> ba < ab --> both cases remain b
8. *a ba --> ba < ab --> both choices remain a
9. *b ba --> trivial
*/

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline string remove(int& point, const string& s, const string sub, const int gain){

        string sta = "";
        for(const char& c: s){
            if(sta.size() >= 1 && sta.back() == sub[0] && c == sub[1]){
                sta.pop_back();

                point += gain;
            }else{
                sta += c;
            }
        }
        return sta;
    }

    int maximumGain(string s, int x, int y) {
        if(x < y){
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int point = 0;
        s = remove(point, s, "ab", x);
        remove(point, s, "ba", y);
        return point;
    }
};
