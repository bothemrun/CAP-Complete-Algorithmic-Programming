#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<tii> val2i(n);
        for(int i=0;i<n;i++) val2i[i] = tii(arr[i], i);
        sort(val2i.begin(), val2i.end());

        vector<int> ans(n);
        for(int j=0;j<n;j++){
            if(j-1 >= 0){
                if( get<0>(val2i[j]) == get<0>(val2i[j-1]) ){
                    ans[ get<1>(val2i[j]) ] = ans[ get<1>(val2i[j-1]) ];
                }else{
                    ans[ get<1>(val2i[j]) ] = ans[ get<1>(val2i[j-1]) ] + 1;           
                }
            }else{
                ans[ get<1>(val2i[j]) ] = 1;
            }
        }
        return ans;
    }
};
