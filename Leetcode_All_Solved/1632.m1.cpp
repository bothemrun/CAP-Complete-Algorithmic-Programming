//m1
//without topological sort in O(mn * (logm + logn) ) & lengthy codes

//[A] it forms a DAG.

//1. assign DAG leaves with 1. then 2, 3, and so on.


//[B] for p==q in the same row/col, they form a group.

//1. so we operate on group roots.


//[C] organized with group root, idx, & (i, j) indexing:

//1. mainly operate on roots, including the ranking.
//2. finally assign each (i, j)'s rank by root2rank.


//O(mn * logmn )

#define tii tuple<int,int>
#define idx(i, j) ( (i)*n + j ) //i*n is wrong
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
        if(dsu[a] == a) return a;
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
            unordered_map<int, vector<int>> val2idxes;
            for(int j=0;j<n;j++) val2idxes[ matrix[i][j] ].push_back( idx(i, j) );

            for(const auto& [_, idxes]: val2idxes)if(idxes.size() >= 2){
                //ok with [0] & [0]
                for(const int& idx: idxes) set_join(idxes.front(), idx);
            }
        }
        for(int j=0;j<n;j++){
            unordered_map<int, vector<int>> val2idxes;
            for(int i=0;i<m;i++) val2idxes[ matrix[i][j] ].push_back( idx(i, j) );

            for(const auto& [_, idxes]: val2idxes)if(idxes.size() >= 2){
                for(const int& idx: idxes) set_join(idxes.front(), idx);
            }
        }


        //finished set joining
        unordered_map<int, unordered_set<int>> root2row;
        unordered_map<int, unordered_set<int>> root2col;
        set<tii> root_set;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int root = set_find( idx(i, j) );

                root2row[root].insert(i);
                root2col[root].insert(j);

                root_set.insert(tii( matrix[i][j], root ));
            }
        
        
        
        vector<int> row2max_rank(m, 0);
        vector<int> col2max_rank(n, 0);
        
        //now roots by their values
        unordered_map<int, int> root2rank;
        for(const auto& [_, root]: root_set){
            //traverse all rows & cols of this group
            int max_rank = 0;
            for(const int& row: root2row[root]){
                max_rank = max(max_rank, row2max_rank[row]);
            }
            for(const int& col: root2col[root]){
                max_rank = max(max_rank, col2max_rank[col]);
            }

            //this root
            root2rank[root] = max_rank + 1;

            //update all rows & cols of this group
            for(const int& row: root2row[root]){
                row2max_rank[row] = max_rank + 1;
            }
            for(const int& col: root2col[root]){
                col2max_rank[col] = max_rank + 1;
            }
        }


        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                matrix[i][j] = root2rank[ set_find( idx(i, j) ) ];
            }
        return matrix;
    }
};
