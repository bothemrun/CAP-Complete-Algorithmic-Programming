//m0
//O(n)
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;

        function<bool(const int&, const int&)> cmp = [&positions](const int& a, const int& b){
            return positions[a] < positions[b];
        };
        sort(idx.begin(), idx.end(), cmp);


        //stack
        vector<int> sta;

        for(const int& i: idx){
            if(sta.size() == 0){
                sta.push_back(i);
                continue;
            }

            if(!( directions[sta.back()]=='R' && directions[i]=='L' )){
                sta.push_back(i);
                continue;
            }

            bool push_i = true;
            while( sta.size() && directions[sta.back()]=='R' ){
                int j = sta.back();

                if(healths[j] > healths[i]){
                    push_i = false;
                    healths[j]--;
                    break;
                }else if(healths[j] < healths[i]){
                    sta.pop_back();
                    healths[i]--;
                }else{
                    push_i = false;
                    sta.pop_back();
                    break;
                }
            }

            if(push_i==true){
                sta.push_back(i);
            }
        }

        sort(sta.begin(), sta.end());
        vector<int> ans;
        for(const int& i: sta){
            ans.push_back(healths[i]);
        }
        return ans;
    }
};
