//all operations in O(1), including toString()

#include<unordered_set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Bitset {
public:
    int size;
    unordered_set<int> bits_unflipped;

    bool flipped = false;
    //NOTE: they are mirrors to each other.
    string str[2];

    Bitset(int size) {
        this->size = size;
        str[0] = string(size, '0');
        str[1] = string(size, '1');
    }
    
    void fix(int idx) {
        if(!flipped){
            bits_unflipped.insert(idx);
            str[false][idx] = '1';
            str[true][idx] = '0';
        }else{
            bits_unflipped.erase(idx);
            str[true][idx] = '1';
            str[false][idx] = '0';
        }
    }
    
    void unfix(int idx) {
        if(!flipped){
            bits_unflipped.erase(idx);
            str[false][idx] = '0';
            str[true][idx] = '1';
        }else{
            bits_unflipped.insert(idx);
            str[true][idx] = '0';
            str[false][idx] = '1';
        }
    }
    
    void flip() {
        flipped = !flipped;
    }
    
    bool all() {
        if(!flipped) return bits_unflipped.size() == size;
        else return bits_unflipped.size() == 0;
    }
    
    bool one() {
        if(!flipped) return bits_unflipped.size() != 0;
        else return bits_unflipped.size() != size;
    }
    
    int count() {
        if(!flipped) return bits_unflipped.size();
        else return size - (int)bits_unflipped.size();
    }
    
    string toString() {
        return str[flipped];
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
