//m0
//binary search the answer
//O(n^2logn)

class Solution {
public:
    int n;
    inline bool good(const string& s, const int len){
        if(len==0) return true;

        unordered_set<string> uset;
        for(int i=0;i+(len-1)<n;i++){
            string sub = s.substr(i, len);
            if(uset.find(sub) != uset.end()) return true;

            uset.insert(sub);
        }
        return false;
    }

    int binary_ans(const string& s, int low, int high){
        int mid = low + (high-low)/2;
        bool mid_res = good(s, mid);
        if(mid_res==true && good(s, mid+1)==false) return mid;

        if(mid_res) return binary_ans(s, mid+1, high);
        else return binary_ans(s, low, mid);
    }
    int longestRepeatingSubstring(string s) {
        this->n = s.size();

        return binary_ans(s, 0, n);
    }
};
