//m0
//O(n) order sized class by multiset template typename

#include<set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

auto cmp_max = [](const int& a, const int& b){
    return a<b;//increasing
};

auto cmp_min = [](const int& a, const int& b){
    return a>b;//decreasing
};

//template typename for 2 different comparators
template <typename T> class order_sized{
private:
    int size_cap;
    multiset<int, T> ms;
public:
    order_sized(T cmp, const int& size_cap_){
        ms = multiset<int, T>(cmp);
        size_cap = size_cap_;
    }

    void push(const int& x){
        ms.insert(x);

        if(ms.size() > size_cap) ms.erase( ms.begin() );
    }

    //function polymorphism
    void push(const class order_sized* os2){
        for(const int& x: os2->ms){
            push(x);
        }
    }

    long long top_product(const int& k){
        assert(k <= ms.size());

        long long res = 1;
        auto it = ms.rbegin();
        for(int i=0;i<k;i++, it++){
            res *= (long long)*it;
        }
        return res;
    }

    int size(){
        return ms.size();
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> al;

    vector<long long> coin;
    vector< class order_sized< decltype(cmp_max) >* > max3;
    vector< class order_sized< decltype(cmp_min) >* > min2;

    void postorder(const vector<int>& cost, const int& node, const int& par=(-1)){
        max3[node] = new class order_sized< decltype(cmp_max) >(cmp_max, 3);
        min2[node] = new class order_sized< decltype(cmp_min) >(cmp_min, 2);

        max3[node]->push(cost[node]);
        min2[node]->push(cost[node]);

        for(const int& child: al[node])if(child != par){
            postorder(cost, child, node);

            max3[node]->push( max3[child] );
            min2[node]->push( min2[child] );
        }

        if(max3[node]->size() < 3){
            coin[node] = 1;
            return;
        }

        coin[node] = max({
            0LL,
            max3[node]->top_product(3),
            min2[node]->top_product(2) * max3[node]->top_product(1)
        });
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        n = edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        coin.resize(n);
        max3.resize(n);
        min2.resize(n);

        const int root = 0;
        postorder(cost, root);

        for(auto ptr: max3) delete ptr;
        for(auto ptr: min2) delete ptr;
        return coin;
    }
};
