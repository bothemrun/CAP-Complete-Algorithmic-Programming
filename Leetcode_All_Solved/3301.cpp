static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        long long ans = 0;
        
        unordered_set<int> ban;
        ban.insert(0);
        
        set<int> avail;
        for(int i=0;i<(int)maximumHeight.size();i++){
            const int maxh = maximumHeight[i];
            int h = INT_MIN;
            if(i == 0 || maximumHeight[i-1] < maxh){
                h = maxh;
            }else if(avail.size() == 0){
                return (-1);
            }else{
                h = *avail.rbegin();
                //assert(ban.find(h) == ban.end());
                avail.erase(h);
            }
            assert(h != INT_MIN);
            
            //printf("%d %d\n", i, h);
            ans += h;
            ban.insert(h);
            if(ban.find(h-1) == ban.end()){
                avail.insert(h-1);
                //printf("avail insert : %d\n", h-1);
            }
        }
        //cout<<endl;
        return ans;
    }
};
