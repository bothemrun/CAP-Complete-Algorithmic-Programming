class Solution {
private:
    vector<int> numbers;
    void dfs(const int& limit, int x=0){
        if(x > limit)return;
        if(x != 0)numbers.push_back(x);
        for(int i=0;i<=9;i++){
            if(x == 0 && i == 0)continue;
            dfs(limit, x*10 + i);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        dfs(n);
        return numbers;
    }
};
