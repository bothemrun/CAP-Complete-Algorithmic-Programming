class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for(const string& s: arr) cnt[s]++;

        int distinct = 0;
        for(const string& s: arr)if(cnt[s] == 1){
            if(++distinct == k) return s;
        }
        return "";
    }
};
