//O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> suf_min(n);
        suf_min.back() = arr.back();
        for(int i=n-2;i>=0;i--){
            suf_min[i] = min(arr[i], suf_min[i+1]);
        }

        int partition = 0;
        int pref_max = INT_MIN;
        for(int i=0;i<n;i++){
            pref_max = max(pref_max, arr[i]);

            if(i+1<n && pref_max <= suf_min.at(i+1)){
                partition++;
                pref_max = INT_MIN;
            }
        }
        //edge case, trap
        partition++;//last part
        return partition;
    }
};
