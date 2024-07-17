//m0

//[A] it forms a DAG.

//1. assign DAG leaves with 1. then 2, 3, and so on.


//[B] for p==q in the same row/col, they form a group.

//1. we now operate on dsu groups. initially each cell is a group.
//2. we'll have parallel edges.
//3. and their indegree is counted together as 1 node.


//O(mn * union find amortized cost) + O(mnlogn + nmlogm ) = O(mn * (logm + logn) )
#define idx(i, j) ( (i)*n + j ) //i*n is wrong
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    inline void set_init(const int size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == a) return dsu[a];
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]){
            dsu[a] = b;
        }else if(rank[a] > rank[b]){
            dsu[b] = a;
        }else{
            dsu[a] = b;

            rank[b]++;
        }
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        set_init(m*n);
        for(int i=0;i<m;i++){
            unordered_map<int, vector<int> > val2idxes;
            for(int j=0;j<n;j++){
                val2idxes[ matrix[i][j] ].push_back( idx(i, j) );
            }
            for(const auto& [_, idxes]: val2idxes)if(idxes.size() >= 2){
                for(const int& idx: idxes){
                    //ok with [0] & [0]
                    set_join(idxes.front(), idx);
                }
            }
        }
        for(int j=0;j<n;j++){
            unordered_map<int, vector<int> > val2idxes;
            for(int i=0;i<m;i++){
                val2idxes[ matrix[i][j] ].push_back( idx(i, j) );
            }
            for(const auto& [_, idxes]: val2idxes)if(idxes.size() >= 2){
                for(const auto& idx: idxes){
                    set_join(idxes.front(), idx);
                }
            }
        }

        //all operate on group root idx, 'cuz we view a group as 1 node.
        vector<vector<int>> al(m*n);
        vector<int> indegree(m*n, 0);
        for(int i=0;i<m;i++){
            vector<tii> row(n);
            for(int j=0;j<n;j++){
                row[j] = tii( matrix[i][j], idx(i, j) );
            }
            sort(row.begin(), row.end());

            for(int j=0;j+1<n;j++){
                const auto& [val1, idx1] = row[j];
                const auto& [val2, idx2] = row[j+1];
                int root1 = set_find(idx1);
                int root2 = set_find(idx2);

                if(val1 < val2){
                    al[root1].push_back(root2);
                    indegree[root2]++;
                }
            }
        }
        for(int j=0;j<n;j++){
            vector<tii> col(m);
            for(int i=0;i<m;i++){
                col[i] = tii( matrix[i][j], idx(i, j) );
            }
            sort(col.begin(), col.end());

            for(int i=0;i+1<m;i++){
                const auto& [val1, idx1] = col[i];
                const auto& [val2, idx2] = col[i+1];
                int root1 = set_find(idx1);
                int root2 = set_find(idx2);

                if(val1 < val2){
                    al[root1].push_back(root2);
                    indegree[root2]++;
                }
            }
        }

        
        //reverse map: group root: group idxes
        unordered_map<int, vector<int> > root2idxes;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                root2idxes[ set_find( idx(i, j) ) ].push_back( idx(i, j) );
            }


        //topological sort
        //all operate on group root.
        unordered_map<int, int> root2rank;

        queue<int> q;
        vector<bool> ever2q(m*n, false);
        for(const auto& [root, idxes]: root2idxes)if(indegree[root] == 0){
            q.push(root);
            ever2q[root] = true;

            root2rank[root] = 1;
        }

        int level = 1;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                //all are group root idx.
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 0){
                        q.push(v);
                        ever2q[v] = true;
                    }

                    root2rank[v] = max(root2rank[v], root2rank[u] + 1);
                }
            }
        }

        //the same group has the same rank
        //now operate on real i, j
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                matrix[i][j] = root2rank[ set_find( idx(i, j) ) ];
            } 
        return matrix;
    }
};
