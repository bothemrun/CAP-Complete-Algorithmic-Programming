//m0
//bfs in O(abs(x-y))

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> q;
        unordered_set<int> ever2q;

        q.push(x);
        ever2q.insert(x);

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                if(u == y) return level;

                vector<int> al({u-1, u+1});
                if(u%11==0) al.push_back(u/11);
                if(u%5==0) al.push_back(u/5);

                for(const int& v: al)if(ever2q.find(v) == ever2q.end()){
                    q.push(v);
                    ever2q.insert(v);
                }
            }

            level++;
        }

        assert(false);
        return INT_MAX;
    }
};
