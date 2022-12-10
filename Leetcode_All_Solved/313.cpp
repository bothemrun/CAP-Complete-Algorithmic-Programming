//m0
//priority queue
#include<queue>
#include<unordered_map>

class cmp_class{
public:
    bool operator()(const long long& a, const long long& b){
        return a > b;//min heap, sink down
    }
};

class Solution {
public:
    priority_queue<long long, vector<long long>, cmp_class> min_heap;
    unordered_map<long long, vector<int>> multi2prime_id;

    void insert(const long long& multi, const int& prime_id){
        if(multi2prime_id.count(multi) == 0){
            multi2prime_id[multi] = vector<int>({prime_id});

            min_heap.push(multi);
        }else multi2prime_id[multi].push_back(prime_id);
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p = primes.size();
        
        //min_heap.push(1);
        for(int i=0;i<p;i++){
            insert(primes[i], i);
        }
        
        vector<int> prime_ugly_idx = vector<int>(p, 0);
        vector<long long> dp_ugly({1});

        for(int i=1;i<n;i++){
            long long ugly = min_heap.top();
            dp_ugly.push_back(ugly);
            min_heap.pop();

            //NOTE: increment, dedup
            for(const int& prime_id: multi2prime_id[ugly]){
                prime_ugly_idx[prime_id]++;
                insert( 
                    dp_ugly[ 
                        prime_ugly_idx[prime_id] 
                        ] * 
                        primes[prime_id], 
                    prime_id );
            }
        }

        return dp_ugly[n-1];
    }
};


