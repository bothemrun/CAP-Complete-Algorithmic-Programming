//if we use a hash table, then O(1) for add(), O(n) for find().

//assume we call add() for x times, and find() for y times.
//since x+y = 10^4
//the by arithmetic inequality, (x+y)/2 >= sqrt(x*y)
//so the overall time complexity = x*y <= ( (x+y)/2 )^2 = (10^4 / 2)^2 = 2.5 * 10^7

#define max_num ((int)1e5)
#define value_bound (2*max_num)
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class TwoSum {
public:
    unordered_map<int,int> val2cnt;
    TwoSum() {
        
    }
    
    void add(int number) {
        //if not exist, then build [number] as 0
        val2cnt[number]++;
    }
    
    bool find(int value) {
        //NOTE: edge:
        if(!( -value_bound <= value && value <= value_bound ))
            return false;


        for(const auto& [val1, cnt]: val2cnt){
            int val2 = value - val1;
            if(val1 == val2){
                //NOTE: important
                if(val2cnt[val1] >= 2) return true;
            }else{
                if(val2cnt.count(val2) != 0) return true;
            }
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
