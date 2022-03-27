class Solution {
private:
    inline void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    inline void swap_interval(vector<int>& nums, const int& front1, const int& front2, const int& size){
        for(int i=0;i<size;i++) swap(nums.at(front1+i), nums.at(front2+i));
    }
    inline void set_smaller(int& front_s, int& size_s, int& front_l, int& size_l){
        if(!(size_s <= size_l)){
            swap(front_s, front_l);
            swap(size_s, size_l);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        int front_s = 0, size_s = nums.size() - k;
        int front_l = nums.size()-1 - k + 1, size_l = k;
        set_smaller(front_s, size_s, front_l, size_l);
        while(size_s != 0){
            //now exchange 2 parts
            //always put the the smaller part to the largr part's end far from the smaller part:
            //if [small, large]: put small in large's back end
            //if [large, small]: put small in large's front end
            if(front_s <= front_l){//small part is lower
                int back_l = front_l + (size_l-1);
                swap_interval(nums, front_s, back_l - (size_s-1), size_s);
            }else{//small part is higher
                swap_interval(nums, front_s, front_l, size_s);
                front_l += size_s;
            }
            
            size_l -= size_s;
            
            set_smaller(front_s, size_s, front_l, size_l);
        }
    }
};
