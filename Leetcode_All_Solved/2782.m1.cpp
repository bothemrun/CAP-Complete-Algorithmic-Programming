//m1

//[A] O(n^2) by amortized O(1) operation of union by rank with path compression.

//[B] pruning:

//1. in the for loop, i & j joined, then break.
//2. what about i with {j+3, j+7, ...}?
//3. j+3 can join j, j+7 can join j+3, and so on.

/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
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
    int dsu_cnt;
    inline void set_init(const int size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        dsu_cnt = size;
        rank.resize(size, 1);
    }

    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }

    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        dsu_cnt--;
        
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
        set_init(n);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if( categoryHandler->haveSameCategory(i, j) == true ){
                    set_join(i, j);

                    //pruning
                    break;
                }
            }
        return dsu_cnt;
    }
};
