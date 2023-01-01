#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<utility>
class Solution {
public:
    int jug1, jug2, target;
    
    int count(unordered_map<int, unordered_set<int>>& state, const int& v1, const int& v2){
        if(state.count(v1) == 0)return 0;
        return state[v1].count(v2);
    }

    void enqueue(queue<pair<int,int>>& q, unordered_map<int, unordered_set<int>>& state, const int& v1, const int& v2){
        if(count(state, v1, v2) != 0)return;

        if(state.count(v1) != 0) state[v1].insert(v2);
        else state[v1] = unordered_set<int>( {v2} );

        q.push( pair<int,int>(v1, v2) );
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        jug1 = jug1Capacity;
        jug2 = jug2Capacity;
        target = targetCapacity;

        unordered_map<int, unordered_set<int>> state;

        queue<pair<int,int>> q;
        enqueue(q, state, 0, 0);

        while(q.size() != 0){
            pair<int,int> n = q.front();
            q.pop();
            int v1 = n.first;
            int v2 = n.second;
            if(v1 == target || v2 == target || v1+v2 == target)return true;

            enqueue(q, state, jug1, v2);
            enqueue(q, state, v1, jug2);
            enqueue(q, state, v1, 0);
            enqueue(q, state, 0, v2);

            //2 to 1
            if(v1+v2 <= jug1) enqueue(q, state, v1+v2, 0);
            else enqueue(q, state, jug1, v1+v2 - jug1 );

            //1 to 2
            if(v1+v2 <= jug2) enqueue(q, state, 0, v1+v2);
            else enqueue(q, state, v1+v2 - jug2, jug2);
        }
        return false;
    }
};


//NOTE: dfs stack overflow
/*
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    unordered_map<int, unordered_set<int>> state;
    int jug1, jug2, target;
    int count(const int& v1, const int& v2){
        if(state.count(v1) == 0)return 0;
        return state[v1].count(v2);
    }
    void insert(const int& v1, const int& v2){
        if(state.count(v1) != 0) state[v1].insert(v2);
        else state[v1] = unordered_set<int>({v2});
    }
    bool dfs(const int& v1, const int& v2){
        if(v1 > jug1 || v2 > jug2)return false;
        if(v1 == target || v2 == target || v1+v2 == target)return true;

        if(count(v1, v2) != 0)return false;
        insert(v1, v2);

        bool ret = false;
        ret |= dfs(jug1, v2);
        if(ret)return true;
        ret |= dfs(v1, jug2);
        if(ret)return true;
        ret |= dfs(0, v2);
        if(ret)return true;
        ret |= dfs(v1, 0);
        if(ret)return true;

        //2 to 1
        if(v1+v2 <= jug1) ret |= dfs(v1+v2, 0);
        else ret |= dfs(jug1, v2 - (jug1 - v1) );
        if(ret)return true;

        //1 to 2
        if(v1+v2 <= jug2) ret |= dfs(0, v1+v2);
        else ret |= dfs(v1 - (jug2 - v2), jug2);
        if(ret)return true;
        return false;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        jug1 = jug1Capacity;
        jug2 = jug2Capacity;
        target = targetCapacity;

        return dfs(0, 0);
    }
};
*/
