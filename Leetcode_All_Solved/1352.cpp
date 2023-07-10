//add O(1), getProduct O(logN) by binary search the indices of 0

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class ProductOfNumbers {
public:
    vector<int> idx0;
    //NOTE: when it encounters 0, it become 0.
    vector<long long>prefixp;

    ProductOfNumbers() {
        
    }
    int size(){
        return prefixp.size();
    }
    
    void add(int num) {
        if(num == 0){
            int i = size();
            idx0.push_back(i);

            prefixp.push_back(0);
        }else{
            if(size()==0 || prefixp.back() == 0) prefixp.push_back(num);
            else prefixp.push_back( prefixp.back() * num );
        }
    }

    inline int first_greater(const vector<int>& v, const int& val){
        return upper_bound(v.begin(), v.end(), val) - v.begin();
        //NOTE: may be (int)v.size() - 1
    }

    inline int last_smaller(const vector<int>& v, const int& val){
        int first_greater_equal = lower_bound(v.begin(), v.end(), val) - v.begin();
        return first_greater_equal - 1;
        //NOTE: may be (-1)
    }

    int getProduct(int k) {
        int high = size()-1;
        int low = size()-k;

        if(
            last_smaller(idx0, low) + 1 == 
            first_greater(idx0, high)
        ){
            if( !(low-1 >= 0) ) return prefixp.at(high);
            else if( prefixp.at(low-1) == 0) return prefixp.at(high);
            else return prefixp.at(high) / prefixp.at(low-1);
        }else return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
