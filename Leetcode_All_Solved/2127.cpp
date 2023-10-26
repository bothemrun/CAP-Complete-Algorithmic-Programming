//Thinking Process
//1. must draw a picture

//[A] a single chain
//1. head & tail not connected, no.

//[B] cycle
//1. for a cycle, the cycle must have all the same directions, since out degree == 1
//2. for a cycle with nodes >= 3, since a person can sit next to 2 persons.
//3. hence, chains joining the cycle are not valid.

//[C] cycles with nodes == 2
//1. the persons in the cycle only sit next to 1 person.
//2. hence 2 chaings can join the 2 person respectively

//[D] combining 2 cycles
//1. since [C] doesn't need the 2 chains' tails to be connected,
//2. hence we can combine multiple [C].

//[E] asn = max( max [B], [D] )
//or === max( max[B], sum [C] )

//[F] how?
//1. use topological sort to get the queue with all cyclic nodes remained
//2. then do dfs, then each cycle is distinguished.
//3. also keep the chain length information while running topological sort.
//O(n) overall

#include<queue>
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
    vector<bool> visited4cycle;
    vector<int> chain_len;

    void dfs(const vector<int>& al, const int& u, int& cycle_len, int& chain_len_sum){
        if(visited4cycle[u] == true) return;
        visited4cycle[u] = true;

        cycle_len++;
        chain_len_sum += chain_len[u];

        dfs(al, al[u], cycle_len, chain_len_sum);
    }

    int maximumInvitations(vector<int>& favorite) {
        vector<int>& al = favorite;
        int n = al.size();

        queue<int> q;
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++)
            indegree[ al[i] ]++;
        
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);


        visited4cycle.resize(n, false);
        chain_len.resize(n, 0);
        
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                visited4cycle[u] = true;


                int v = al[u];
                
                chain_len[v] = 1 + chain_len[u];
                
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }



        int max_cycle3 = 0;
        int sum_cycle2 = 0;
        for(int u=0;u<n;u++)if(visited4cycle[u] == false){
            int cycle_len = 0;
            int chain_len_sum = 0;

            dfs(al, u, cycle_len, chain_len_sum);

            if(cycle_len == 2)
                sum_cycle2 += cycle_len + chain_len_sum;
            else max_cycle3 = max(max_cycle3, cycle_len);
        }

        return max(max_cycle3, sum_cycle2);
    }
};
