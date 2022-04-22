#include<algorithm>
class Solution {
private:
    inline int f(const string& s){
        char lexi_min = (char)126; //(char)255;
        for(int i=0;i<(int)s.size();i++)if(lexi_min > s[i])lexi_min = s[i];
        int cnt = 0;
        for(int i=0;i<(int)s.size();i++)if(s[i] == lexi_min)cnt++;
        return cnt;
    }
    int n_words;
    int binary_bound(const vector<int>& arr, const int& target, int low, int high){//find low bound
        int mid = low + (high-low)/2;
        //printf("%d %d %d %d\n", low, mid, arr[mid], high);
        if(mid == 0 && target < arr[mid])return n_words - low;
        if(mid != 0 && arr[mid-1] <= target && arr[mid] > target)return n_words - mid;
        if(low == high)return 0;//not found
        
        if(arr[mid] <= target)return binary_bound(arr, target, mid+1, high);
        else return binary_bound(arr, target, low, mid);
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        n_words = words.size();
        vector<int> words_f;
        vector<int> queries_f;
        for(const string& w:words) words_f.push_back(f(w));
        for(const string& q:queries) queries_f.push_back(f(q));
        sort(words_f.begin(), words_f.end());
        
        vector<int> ans;
        //for(int i=0;i<words_f.size();i++)cout << words[i] << " " << words_f[i] << "\n";
        for(int i=0;i<queries_f.size();i++){
            //cout << queries[i] << " " << queries_f[i] << "\n";
            ans.push_back( binary_bound(words_f, queries_f[i], 0, words_f.size()-1) );
        }
        return ans;
    }
};
