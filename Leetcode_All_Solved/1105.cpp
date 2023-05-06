//m0
//recursion with memo
#define notyet (-1)
#include<algorithm>
#include<limits.h>

bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    vector<int> prefix_width;
    vector<int> memo;
    int enum_last_level(const vector<vector<int>>& books, const int& i, const int& shelfWidth){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        int mi = INT_MAX;
        for(int last=i;last>=0;last--){
            int width = prefix_width[i] - ( (last-1>=0)? prefix_width[last-1]:0 );
            if(width > shelfWidth) break;

            int height = max_element(books.begin() + last, books.begin()+i+1, cmp_fn)->at(1);

            mi = min(
                mi,
                height + enum_last_level(books, last-1, shelfWidth)
            );
        }
        return memo[i] = mi;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        prefix_width.resize(n);
        prefix_width[0] = books[0][0];
        for(int i=1;i<n;i++) prefix_width[i] = books[i][0] + prefix_width[i-1];

        memo.resize(n, notyet);
        return enum_last_level(books, n-1, shelfWidth);
    }
};
