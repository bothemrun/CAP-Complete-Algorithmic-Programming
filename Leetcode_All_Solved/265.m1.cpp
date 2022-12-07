//m1
//method 0 is O(nk logk) ~= O(nk) when k small
//method 1 is real O(nk)
#include<assert.h>
#include<algorithm>

struct cost_color{
    int cost;
    int color;
};

class top2{
private:
    vector<struct cost_color> v;
    const int max_size = 2;
public:
    void push(const int& cost, const int& color){
        struct cost_color cc = {cost, color};
        if(v.size() < max_size) v.push_back(cc);
        else{//NOTE: ok for equal costs
            /*
            if(v[0].cost > cost) v[0] = cc;
            else if(v[1].cost > cost) v[1] = cc;
            */
            if( cost > top2nd().cost )return;//NOTE: can't improve neither
            top2nd() = cc;
        }
    }
    const struct cost_color& top() const{
        assert(v.size() == max_size);//problem setting k>=2
        return (v[0].cost < v[1].cost)? v[0]:v[1];
    }
    struct cost_color& top2nd(){
        assert(v.size() == max_size);//problem setting k>=2
        return (v[0].cost < v[1].cost)? v[1]:v[0];
    }
    void clear(){
        v.clear();
    }
};


class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();

        vector<class top2> prev_top2(2);
        for(int j=0;j<k;j++)
            prev_top2[0].push( costs[0][j], j );

        
        for(int i=1;i<n;i++){
            //NOTE: use prev_top2[(i+1)%2], and store in prev_top2[i%2]
            prev_top2[i%2].clear();//NOTE: clear to store

            for(int j=0;j<k;j++){
                int prev_min_cost;
                if(prev_top2[(i+1)%2].top().color == j)
                    prev_min_cost = prev_top2[(i+1)%2].top2nd().cost;
                else prev_min_cost = prev_top2[(i+1)%2].top().cost;

                //update, store
                prev_top2[i%2].push( prev_min_cost + costs[i][j], j );
            }
        }

        return prev_top2[(n-1)%2].top().cost;
    }
};





