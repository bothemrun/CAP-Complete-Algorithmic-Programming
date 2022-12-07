#define test 0
#include<assert.h>
#include<limits.h>
#include<queue>
struct cost_color{
    int cost;
    int color;
    cost_color(const int& cost_, const int& color_){
        cost = cost_;
        color = color_;
    }
};

class cmp_class{
public:
    bool operator()(const struct cost_color& a, const struct cost_color& b){
        return a.cost > b.cost;//NOTE: min heap
    }
};

inline void push2(const int& cost, const int& color, priority_queue<struct cost_color, vector<struct cost_color>, cmp_class>& prev_min_heap){
    //prev_min_heap.push( new cost_color(cost, color) );
    struct cost_color cc = {cost, color};
    prev_min_heap.push( cc );
    
    //NOTE: if(prev_min_heap.size() > 2) prev_min_heap.pop();
}

inline void clear(priority_queue<struct cost_color, vector<struct cost_color>, cmp_class>& prev_min_heap){
    while(prev_min_heap.size() != 0) prev_min_heap.pop();
}

#if test == 1
inline void print(priority_queue<struct cost_color, vector<struct cost_color>, cmp_class>& prev_min_heap){
    cout << " size: " << prev_min_heap.size() << " heap: ";
    vector<struct cost_color> tmp;
    while(prev_min_heap.size() != 0){
        tmp.push_back( prev_min_heap.top() );
        printf("(%d,%d) ", prev_min_heap.top().cost, prev_min_heap.top().color);
        prev_min_heap.pop();
    }

    for(struct cost_color cc: tmp)
        prev_min_heap.push(cc);

}
#endif

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        //vector<vector<int>> dp_seen(n, vector<int>(k));
        //dp_seen[0] = costs[0];

        vector< priority_queue<struct cost_color, vector<struct cost_color>, cmp_class> > prev_min_heap(2, priority_queue<struct cost_color, vector<struct cost_color>, cmp_class>() );
        for(int j=0;j<k;j++)
            push2(costs[0][j], j, prev_min_heap[0]);


        for(int i=1;i<n;i++){
            
            clear( prev_min_heap[i%2] ); //NOTE: clear storing

            for(int j=0;j<k;j++){
                //NOTE: prev_min_heap: use [(i+1)%2], and store in [i%2]
                int min_cost;
                if(prev_min_heap[(i+1)%2].top().color == j){
                    struct cost_color cc_tmp = prev_min_heap[(i+1)%2].top();
                    prev_min_heap[(i+1)%2].pop();
                    
                    min_cost = prev_min_heap[(i+1)%2].top().cost;

                    push2(cc_tmp.cost, cc_tmp.color, prev_min_heap[(i+1)%2]);
                }else{
                    min_cost = prev_min_heap[(i+1)%2].top().cost;
                }

                
                //dp_seen[i][j] = costs[i][j] + min_cost;

                //NOTE: update, store
                //push2( dp_seen[i][j], j, prev_min_heap[i%2] );
                push2( costs[i][j] + min_cost, j, prev_min_heap[i%2] );
                
                #if test == 1
                printf("[%d %d] ", i, j);
                cout << costs[i][j] + min_cost;
                print(prev_min_heap[i%2]);
                printf("[%d %d] \n", i, j);
                cout << ( (j==k-1)? '\n':' ');
                #endif
            }
        }

        #if test == 1
        cout << endl;
        print(prev_min_heap[(n-1)%2]);
        #endif
        
        return prev_min_heap[(n-1)%2].top().cost;
    }
};





