#define test 0 //1 0
#include<algorithm>
#include<limits.h>
#include<assert.h>
bool cmp_fn(const int& a, const int& b){
    return a > b;//decreasing
}
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digit;
        int x = n;
        while(x != 0){
            digit.push_back(x%10);
            x /= 10;
        }
        int d = digit.size();

        int i=1;
        while(i < d && !(digit[i-1] > digit[i]) ) i++;
        if(i == d)return (-1);


        int j = i-1;
        assert(digit[j] > digit[i]);
        while(j-1 >= 0 && digit[j-1] > digit[i]) j--;

        swap(digit[j], digit[i]);
        sort(digit.begin(), digit.begin() + (i-1) - (0-1), cmp_fn );

        #if test == 1
        printf("i %d j %d\n", i, j);
        for(int k=0;k<d;k++)
            cout << digit[k] << " ";
        cout<<endl;
        #endif
        
        //NOTE: overflow: int pow10 = 10;
        long long pow10 = 10;
        for(int k=0;k<i;k++) pow10 *= 10;

        long long ans = 0;
        for(int k=i;k>=0;k--)
            ans = ans*10 + digit[k];
        
        ans += n / pow10 * pow10;
        if(ans > INT_MAX) return (-1);
        return (int)ans;
    }
};
