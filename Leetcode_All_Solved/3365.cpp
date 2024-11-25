static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int len = n / k;
        
        unordered_map<string, int> umap;
        for(int i=0;i<n;i += len){
            string sub = s.substr(i, len);
            //sort(sub.begin(), sub.end());//XXX
            umap[sub]++;
        }
        
        for(int i=0;i<n;i += len){
            string sub = t.substr(i, len);
            //sort(sub.begin(), sub.end());//XXX
            if( umap[sub] <= 0){
                return false;
            }
            
            umap[sub]--;
        }
        return true;
    }
};
