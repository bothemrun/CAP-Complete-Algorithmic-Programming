#include<queue>
#include<utility>
#include<unordered_map>
#include<algorithm>
//NOTE: class cmp_obj{
class cmp_class{
public:
    bool operator()(const pair<int,string>& p1, const pair<int,string>& p2){
        if(p1.first != p2.first) return p1.first > p2.first;//min heap
        else return p1.second < p2.second;//max heap
    }
};
class Solution {
private:
    /*static bool cmp_ptr(const pair<int,string>& p1, const pair<int,string>& p2){
        if(p1.first != p2.first) return p1.first < p2.first;//max heap
        else return p1.second > p2.second;//min heap
    }*/
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(const string& word:words){
            auto it = freq.find(word);
            if(it == freq.end()) freq[word] = 1;
            else freq[word]++;
        }
        
        //NOTE: priority_queue< pair<int,string>, vector<pair<int,string>>, cmp_ptr> pq;
        //NOTE: priority_queue< pair<int,string>, vector< pair<int,string> >, cmp_obj() > pq;
        priority_queue< pair<int,string>, vector< pair<int,string> >, cmp_class > pq;
        for(auto it = freq.begin();it != freq.end();it++){
            pq.push( pair<int,string>(it->second, it->first) );
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> topk;
        while(pq.size() != 0){
            topk.push_back( pq.top().second );
            pq.pop();
        }
        reverse(topk.begin(), topk.end());
        return topk;
    }
};
