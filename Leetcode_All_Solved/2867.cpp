//m0
//ugly O(n + nloglogn)
//1. prime sieve
//2. undirected graph into a directed tree
//3. tree dp, excluding up & down curls.
//4. up & down curls

#define notyet (-1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<vector<int>> undirected;
    vector<vector<int>> al;

    vector<vector<long long>> memo;

    vector<bool> is_prime;
    inline void prime_sieve(int n){
        //O(nloglogn)
        is_prime.resize(n+1, true);

        is_prime[1] = false;

        for(int p=2;p*p<=n;p++)if(is_prime[p] == true){
            for(int m=p;p*m <=n;m++)
                is_prime[ p*m ] = false;
        }
    }

    void dfs(vector<bool>& visited, const int& root, const int& pre=(-1)){
        if(visited[root] == true) return;
        visited[root] = true;

        if(pre != (-1)){
            al[pre].push_back(root);
        }

        for(const int& child: undirected[root]){
            //don't need pre != child.
            //since we have visited array
            dfs(visited, child, root);
        }
    }

    inline long long enum_path_self(const int& root, const int& prime_cnt){
        long long ret = enum_path(root, prime_cnt);
        ret += prime_cnt == (int)is_prime[root];
        return ret;
    }

    long long enum_curl(const int& root){
        if(is_prime[root] == true){
            //0 up, 0 down
            long long sum0 = 0;
            for(const int& child: al[root]){
                sum0 += enum_path_self(child, 0);
            }

            long long curl = 0;
            for(const int& child: al[root]){
                long long cnt0 = enum_path_self(child, 0);
                sum0 -= cnt0;

                curl += cnt0 * sum0;
            }

            return curl;
        }else{
            //1 up, 0 down
            //0 up, 1 down
            long long sum0 = 0;
            long long sum1 = 0;
            for(const int& child: al[root]){
                sum0 += enum_path_self(child, 0);
                sum1 += enum_path_self(child, 1);
            }

            long long curl = 0;
            for(const int& child: al[root]){
                long long cnt0 = enum_path_self(child, 0);
                long long cnt1 = enum_path_self(child, 1);
                sum0 -= cnt0;
                sum1 -= cnt1;

                curl += cnt0 * sum1;
                curl += cnt1 * sum0;
            }

            return curl;
        }
    }

    long long enum_path(const int& root, const int& prime_cnt){

        if(memo[root][prime_cnt] != notyet) return memo[root][prime_cnt];


        if(is_prime[root] == false){
            long long ret = 0;
            for(const int& child: al[root]){
                ret += enum_path(child, prime_cnt);

                if((int)is_prime[child] == prime_cnt){
                    ret++;
                }
            }
            return memo[root][prime_cnt] = ret;
        }else{
            //root is prime.
            if(prime_cnt == 0){
                return memo[root][prime_cnt] = 0;
            }else{
                long long ret = 0;
                for(const int& child: al[root]){
                    ret += enum_path(child, 0);

                    if(is_prime[child] == false){
                        ret++;
                    }
                }//for
                return memo[root][prime_cnt] = ret;
            }
        }
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        prime_sieve(n);

        undirected.resize(n+1);
        for(const vector<int>& e: edges){
            //keep 1-indexed
            undirected[e[0]].push_back(e[1]);
            undirected[e[1]].push_back(e[0]);
        }

        //NOTE: turn undirected graph into a directed tree
        al.resize(n+1);
        vector<bool> visited(n+1, false);
        dfs(visited, 1);


        memo.resize(n+1, vector<long long>(2, notyet));
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans += enum_path(i, 1);
            ans += enum_curl(i);
        }
        return ans;
    }
};
