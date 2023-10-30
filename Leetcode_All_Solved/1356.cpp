#define max_bit 15
#include<algorithm>

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n, 0);
        for(int i=0;i<n;i++){
            int x = arr[i];

            for(int bit=0, mask=1;bit<=max_bit;bit++, mask<<=1)
                if( (x & mask) )
                    cnt[i]++;
        }

        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;

        auto cmp = [&cnt, &arr](const int& i, const int& j){
            if(cnt[i] != cnt[j]) return cnt[i] < cnt[j];
            return arr[i] < arr[j];
        };
        sort(idx.begin(), idx.end(), cmp);


        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i] = arr[ idx[i] ];
        return ans;
    }
};
