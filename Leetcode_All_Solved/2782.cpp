//O(n^2) by amortized O(1) operation of union by rank with path compression.

/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    int cnt;
    inline void make_set(const int& size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);
        cnt = size;
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        cnt--;

        if(rank[a] < rank[b]){
            dsu[a] = b;
        }else if(rank[a] > rank[b]){
            dsu[b] = a;
        }else{
            dsu[a] = b;
            rank[b]++;
        }
    }

    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        make_set(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( categoryHandler->haveSameCategory(i, j) == true){
                    set_join(i, j);
                    break;
                }
            }
        }

        return cnt;
    }
};
