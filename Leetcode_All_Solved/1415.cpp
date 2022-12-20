class Solution {
public:
    vector<char> chars = {'a', 'b', 'c'};
    vector<string> happy;
    string happy1 = "";

    bool backtrack(const int& n, const int& i, const char& last, const int& k){
        if(i == n){
            //pack
            happy.push_back(happy1);
            //NOTE: early stopping, prune
            if(happy.size() == k)return true;
            return false;
        }

        for(const char& c: chars)if(last != c){
            happy1 += c;
            if( backtrack(n, i+1, c, k) == true)
                return true;
            happy1.erase(happy1.size()-1, 1);
        }
        return false;
    }

    string getHappyString(int n, int k) {
        if( backtrack(n, 0, chars.back()+1, k) == true)
            return happy.back();
        return string();
    }
};
