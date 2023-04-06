class Solution {
public:
    vector<int> ans;
    void backtrack(const int& n, const int& k, string& ans1){
        if(ans1.size() == n){
            ans.push_back(stoi(ans1));
            return;
        }
        
        if(ans1.size() == 0){
            for(int i=1;i<=9;i++){
                ans1 += to_string(i);
                backtrack(n, k, ans1);
                ans1.pop_back();
            }
        }else{
            if(ans1.back() + k <= '9'){
                ans1 += ans1.back() + k;
                backtrack(n, k, ans1);
                ans1.pop_back();
            }
            //NOTE: de-duplicate
            if(k != 0 && ans1.back() - k >= '0'){
                ans1 += ans1.back() - k;
                backtrack(n, k, ans1);
                ans1.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string ans1 = "";
        backtrack(n, k, ans1);
        return ans;
    }
};
