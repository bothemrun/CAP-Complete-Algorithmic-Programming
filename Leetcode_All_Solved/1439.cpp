//m0
//merge m sorted lists, with set of vectors to de-duplicate index vectors.

//O(k) * O(each row index forward) * O(push into heap + check set of vector)
//= O(k) * O(m) * O( log(heap_size) + n * O(set_size) )
//= O(k) * O(m) * O( log(km) + n * O(km) )
//= O(k*m * n*log(k) )

//heap of pair(int sum, int idx_id), not pair(int sum, vector<int> idx_vector ),
//'cuz it would cost O( vector_size * log(heap_size) ) from O( log(heap_size) )

#define PII pair<int,int>
#include<queue>
#include<set>
#include<utility>
#include<assert.h>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat.back().size();

        auto cmp = [](const PII& a, const PII& b){
            return a.first > b.first; //min heap
        };
        priority_queue<PII, vector<PII>, decltype(cmp) > minheap(cmp);

        vector< vector<int> > id2idx;

        set< vector<int> > idx_set;

        auto push = [&minheap, &id2idx, &idx_set](const int& sum, const vector<int>& idx){
            int id = id2idx.size();
            id2idx.push_back(idx);

            minheap.push(PII(sum, id));

            idx_set.insert(idx);
        };

        //no overflow
        int first_sum = 0;
        for(int i=0;i<m;i++) first_sum += mat[i][0];
        vector<int> first_idx(m, 0);
        push(first_sum, first_idx);


        for(int t=0;t<(k-1);t++){
            assert(minheap.size());
            auto [sum, id] = minheap.top();
            minheap.pop();

            //NOTE: crucial!!
            //NOTE: push_back to a vector may cause resize and hence relocation
            //NOTE: then if we use the reference variable,
            //NOTE: heap use after free error will happen!!!!
            //wrong: vector<int>& idx = id2idx[id];
            vector<int> idx = id2idx[id];

            for(int i=0;i<m;i++){
                idx[i]++;

                int pre_col = idx[i] - 1;
                int cur_col = idx[i];
                if(cur_col<n && idx_set.count(idx) == 0){
                    int new_sum = sum - mat[i][pre_col] + mat[i][cur_col];

                    push(new_sum, idx);
                }

                idx[i]--;
            }
        }

        assert(minheap.size());
        return minheap.top().first;
    }
};
