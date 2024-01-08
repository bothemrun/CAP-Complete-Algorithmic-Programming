//O(n) by sliding window instead O(kn) w/o sliding window

class Solution {
public:
    int n;
    inline int idx(int i){
        int index = (i+n)%n;
        assert(0<=index && index<n);
        return index;
    }

    inline void push(const vector<int>& code, vector<int>& ans, int len, int delta){
        int window = 0;
        for(int j=1;j<len;j++){
            int i = idx(j * delta);
            
            window += code[i];
        }

        for(int j=0;j<n;j++){
            int i = idx(j * delta);
            //take
            window += code[ idx( i + delta*len ) ];

            ans[i] = window;

            //drop
            window -= code[ idx(i + delta) ];
        }
    }

    vector<int> decrypt(vector<int>& code, int k) {
        this->n = code.size();
        vector<int> ans(n, 0);

        if(k==0) return ans;

        if(k>0) push(code, ans, abs(k), 1);
        else push(code, ans, abs(k), -1);
        return ans;
    }
};
