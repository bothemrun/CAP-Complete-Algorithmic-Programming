#include<limits.h>
class DataStream {
public:
    int value;
    int k;
    int cnt = 0;
    int closest_bad;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        
        closest_bad = k+1;
    }
    bool good(){
        return closest_bad >= k;
    }
    bool consec(int num) {
        if(num == value){
            closest_bad++;
        }else{
            closest_bad = 0;
        }
        cnt++;
        
        if(cnt < k)return false;
        else return good();
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
