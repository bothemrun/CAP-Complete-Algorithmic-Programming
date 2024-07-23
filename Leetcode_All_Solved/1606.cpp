//m0

//[A] sorted container for the busy servers to store their next available time.

//1. priority queue or multiset of time


//[B] free servers, find next available index fast.

//1. if we use a bool vector, then O(k) each time.
//2. so tree set or multiset of indices in O(logk)

//3. wrap-around --> ok

//O(n * logk)
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        function<bool(const tii&, const tii&)> cmp = [](const tii& a, const tii& b){
            const auto& [at, ai] = a;
            const auto& [bt, bi] = b;
            return at>bt;//minheap, sink down
        };
        priority_queue<tii, vector<tii>, decltype(cmp)> busy_avail_time(cmp);

        multiset<int> free_idx;
        for(int i=0;i<k;i++) free_idx.insert(i);


        int n = arrival.size();
        vector<int> handled(k, 0);

        for(int i=0;i<n;i++){
            int arrive = arrival[i];
            //drop available servers
            while(busy_avail_time.size() && get<0>( busy_avail_time.top() ) <= arrive){
                auto [_, busy_i] = busy_avail_time.top();

                busy_avail_time.pop();

                free_idx.insert(busy_i);
            }

            //drop this request
            if(free_idx.size() == 0) continue;

            //handle
            auto it = free_idx.lower_bound(i%k);
            //wrap-around
            int handle_i = (it == free_idx.end())? *free_idx.begin():*it;
            free_idx.erase( free_idx.find(handle_i) );

            busy_avail_time.push(tii( arrive + load[i], handle_i ));

            //count
            handled[handle_i]++;
        }


        int ma = *max_element(handled.begin(), handled.end());
        vector<int> ans;
        for(int i=0;i<k;i++)if(handled[i] == ma){
            ans.push_back(i);
        }
        return ans;
    }
};
