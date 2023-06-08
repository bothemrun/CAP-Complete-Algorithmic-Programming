//NOTE: integer sorting in O(n).  O(n) totally.
#define output 0 //1 0
#define max_size 1001
class Solution {
public:
    inline void int_sort(vector<int>& arr){
        int cnt[max_size] = {0};//fast init to 0 by array
        for(const int& x: arr) cnt[x]++;

        int i_arr = 0;
        for(int x=0;x<max_size;x++)if(cnt[x] != 0){
            while(cnt[x]-- > 0) arr[i_arr++] = x;
        }

#if output == 1
        for(const int& x: arr) cout<<x<<" ";
        cout<<endl;
#endif
    }

    int hIndex(vector<int>& citations) {
        //NOTE: integer sorting in O(n)
        int_sort(citations);
        
        int n = citations.size();
        int i;
        for(i=n-1;i>=0;i--){
            //[i] bad, then break
            int need_citation = n - i;
            if(citations[i] < need_citation) return (n-1) - i;
        }
        return n;
    }
};
