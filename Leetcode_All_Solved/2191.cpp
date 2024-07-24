#define t3i tuple<int,int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline int get_mapping(const vector<int>& mapping , int x){
        vector<int> digit;

        //edge case x==0
        if(x==0) return mapping[0];

        while(x != 0){
            digit.push_back( mapping[x%10] );
            x /= 10;
        }

        int y = 0;
        for(auto it=digit.rbegin();it != digit.rend();it++) y = y*10 + *it;
        return y;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<t3i> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = t3i(
                get_mapping(mapping, nums[i]),
                i,
                nums[i]
            );
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = get<2>(arr[i]);
        return ans;
    }
};
