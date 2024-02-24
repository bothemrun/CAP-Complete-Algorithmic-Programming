//O(nlogn) due to sorting
//1. relations at the same time form a union set.

//2. then disjoint set union by rank with path compression time by time.

//3. after a meeting time, reset the people who don't know the secrets.
//3.a. the main difficulty is that secrets can be shared instantanously,
//3.b. and how to cancel relations.

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    const int root = (-1);
    inline void make_set(int n){
        dsu.resize(n, root);
        rank.resize(n, 1);
    }

    int set_find(const int& a){
        if(dsu[a] == root) return a;
        else return dsu[a] = set_find(dsu[a]);
    }

    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]) dsu[a] = b;
        else if(rank[a] > rank[b]) dsu[b] = a;
        else{
            dsu[a] = b;
            rank[b]++;
        }
    }

    inline void reset(const int& a){
        dsu[a] = root;
        rank[a] = 1;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
            //by time
        };
        sort(meetings.begin(), meetings.end(), cmp);


        make_set(n);
        const int secret_person = 0;
        set_join(secret_person, firstPerson);

        int m = meetings.size();
        int i=0;
        while(i<m){
            //[start, end] have the same time
            int start = i;
            int end = i;
            while(end+1<m && meetings[i][2] == meetings[end+1][2] ){
                end++;
            }

            for(int j=start;j<=end;j++){
                set_join( meetings[j][0], meetings[j][1] );
            }

            //NOTE: reset / restore dsu
            int secret_set = set_find(secret_person);
            for(int j=start;j<=end;j++)if( set_find(meetings[j][0]) != secret_set ){
                reset(meetings[j][0]);
                reset(meetings[j][1]);
            }

            //update
            i = end+1;
        }

        vector<int> ans;
        int secret_set = set_find(secret_person);
        for(int i=0;i<n;i++)if( set_find(i) == secret_set )
            ans.push_back(i);
        
        return ans;
    }
};
