//m0
//[A] offline query preprocessing --> so we can have a prefix/suffix data structure for room IDs.

//[B] closest ID --> tree set/multiset's binary search

//O(QlogQ + QlogN)

#define t3i tuple<int,int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int qn = queries.size();
        vector<t3i> queries_i(qn);

        for(int i=0;i<qn;i++){
            queries_i[i] = t3i( queries[i][0], queries[i][1], i );
        }

        //room size decreasing
        function<bool(const t3i&, const t3i&)> cmp = [](const t3i& a, const t3i& b){
            return get<1>(a) > get<1>(b);
        };
        sort(queries_i.begin(), queries_i.end(), cmp);


        auto cmp2 = [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];//room sizes decreasing
        };
        sort(rooms.begin(), rooms.end(), cmp2);

        multiset<int> prefix_rooms;
        int room_i = 0;

        vector<int> ans(qn);
        for(const auto& [prefer, min_size, q_i]: queries_i){
            while(room_i < rooms.size() && min_size <= rooms[room_i][1]){
                prefix_rooms.insert( rooms[room_i++][0] );
            }

            
            auto it = prefix_rooms.lower_bound(prefer);
            int close_room = (-1);
            if(it != prefix_rooms.end()){
                close_room = *it;
            }
            if(it != prefix_rooms.begin()){
                int prev_room = *prev(it);

                if( abs(prev_room - prefer) <= abs(close_room - prefer) ){
                    //if tie, lower id.
                    close_room = prev_room;
                }
            }
            ans[q_i] = close_room;
        }
        return ans;
    }
};
