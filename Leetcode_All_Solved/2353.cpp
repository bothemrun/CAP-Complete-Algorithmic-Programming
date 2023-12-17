//each operation in O(logn)
#define PIS pair<int, string>
#include<utility>
#include<unordered_map>
#include<set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const PIS& a, const PIS& b) const{
        if(a.first != b.first) return a.first > b.first;//highest rating
        else return a.second < b.second;//lexicographically
    }
};

class FoodRatings {
public:
    unordered_map<string, string> food2cui;
    unordered_map<string, int> food2rate;
    unordered_map<string, set<PIS, cmp_class> > cui2rate_food;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            food2cui[ foods[i] ] = cuisines[i];
            food2rate[ foods[i] ] = ratings[i];
            cui2rate_food[ cuisines[i] ].insert( PIS( ratings[i], foods[i] ) );
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rate = food2rate[ food ];
        food2rate[ food ] = newRating;

        cui2rate_food[ food2cui[food] ].erase( PIS( old_rate, food ) );

        cui2rate_food[ food2cui[food] ].insert( PIS( newRating, food ) );
    }
    
    string highestRated(string cuisine) {
        return cui2rate_food[ cuisine ].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
