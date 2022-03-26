// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    inline bool good(const int& i){
        if(i == 0)return true;
        else return !isBadVersion(i);
    }
    int binary_search_check_mid(int low, int high){
        int middle = low + (high-low)/2;
        bool mid_good = good(middle);
        bool mid_next_good = good(middle+1);
        
        if(mid_good == true && mid_next_good == false) return middle+1; //also applies for size 1 interval //NOTE case 1
        if(low == high)return (-1);
        
        //NOTE: 4 cases: mid_bad==false (good) & mid_next_bad==true (bad) is impossible
        if(mid_good == false) return binary_search_check_mid(low, middle);//case 2
        else return binary_search_check_mid(middle+1, high); //case 3
    }
public:
    int firstBadVersion(int n) {
        //if(n == 1) return 1;
        return binary_search_check_mid(0, n-1);
    }
};
