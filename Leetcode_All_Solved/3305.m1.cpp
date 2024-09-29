//m1
//exactly from 3306.

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        long long ans = 0;
        unordered_set<char> vowset = {'a', 'e', 'i', 'o', 'u'};
        auto is_vow = [&](int j){
            return vowset.find(word[j]) != vowset.end();
        };
        
        const int no_vow = (-1);
        vector<int> vow_interval(n, no_vow);
        int vow_interval_back = no_vow;
        for(int i=n-1;i>=0;i--){
            if(is_vow(i)){
                if(vow_interval_back == no_vow){
                    vow_interval[i] = i;
                }else{
                    vow_interval[i] = vow_interval_back;
                }
                
                vow_interval_back = vow_interval[i];
            }else{
                vow_interval_back = no_vow;
            }
        }
        /*
        for(int i=0;i<n;i++){
            printf("i%d %c %d\n", i, word[i], vow_interval[i]);
        }*/
        
        int j = 0;
        int consonant = 0;
        unordered_map<char, int> vow2cnt;
        auto good = [&](){
            bool each_vow = true;
            for(char c: vowset)if(vow2cnt[c] == 0){
                each_vow = false;
                break;
            }
            return each_vow && consonant == k;
        };
        for(int i=0;i<n;i++){
            while( (j<n && is_vow(j) && !good() ) || (j<n && !is_vow(j) && consonant < k ) ){
                if(is_vow(j)){
                    vow2cnt[ word[j] ]++;
                }else{
                    consonant++;
                }
                
                j++;
            }
            
            int good_j = j-1;
            if(good()){
                //printf("\ni%d good_j%d ans%d ", i, good_j, ans);
                ans++;
                if(good_j+1<n && is_vow(good_j+1)){
                    assert(vow_interval[good_j+1] != no_vow);
                    ans += vow_interval[good_j+1] - good_j;
                    //printf("ans finally %d", ans);
                }
            }
            /*
            if(good()){
                printf("\ni%d j%d ans%d ", i, j, ans);
                ans++;
                if(j+1<n && is_vow(j)){
                    assert(vow_interval[j+1] != no_vow);
                    ans += vow_interval[j+1] - j;
                    printf("ans finally %d", ans);
                }
            }*/
            
            //update, drop i, not j
            if(is_vow(i)){
                assert( --vow2cnt[ word[i] ] >= 0);
            }else{
                consonant--;
            }
        }
        
        //cout<<endl;
        return ans;
    }
};
