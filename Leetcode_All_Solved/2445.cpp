class Solution {
public:
    int n;
    vector<int> value;
    void preorder(const int& root){
        if(root > n)return;

        value[root] ^= 1;

        preorder(root*2);
        preorder(root*2 + 1);
    }
    int numberOfNodes(int n, vector<int>& queries) {
        this->n = n;
        vector<int> flip(n+1, 0);
        for(const int& q: queries)
            flip[q]++;

        value = vector<int>(n+1, 0);
        for(int i=1;i<=n;i++)if(flip[i]%2 == 1)
            preorder(i);
        
        int cnt = 0;
        for(int i=1;i<=n;i++)if(value[i] == 1)
            cnt++;
        return cnt;
    }
};
