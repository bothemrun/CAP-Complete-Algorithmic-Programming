//m0
//upgrade() costs O(n)
//overall O(2000n) = 4e6

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> al;

    const int no_lock = (-2);
    vector<int> node2user;

    bool dfs_has_lock(int node){
        if(node2user[node] != no_lock) return true;

        bool subtree_ok = false;
        for(const int& child: al[node])
            if(dfs_has_lock(child) == true){
                subtree_ok = true;
                break;
            }
        
        return subtree_ok;
    }

    void dfs_unlock(int node){
        node2user[node] = no_lock;

        for(const int& child: al[node])
            dfs_unlock(child);
    }

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;

        al.resize(n);
        for(int i=0;i<n;i++)if(parent[i] != (-1))
            al[ parent[i] ].push_back(i);
        
        node2user.resize(n, no_lock);
    }
    
    bool lock(int num, int user) {
        //also for the same user
        if(node2user[num] != no_lock) return false;

        node2user[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(node2user[num] == no_lock) return false;
        if(node2user[num] != user) return false;

        node2user[num] = no_lock;
        return true;
    }
    
    bool upgrade(int num, int user) {
        int cur = num;
        while(cur != (-1)){
            if(node2user[cur] != no_lock) return false;
            cur = parent[cur];
        }


        bool subtree_ok = false;
        for(const int& child: al[num])
            if(dfs_has_lock(child) == true){
                subtree_ok = true;
                break;
            }
        
        if(subtree_ok == false) return false;


        dfs_unlock(num);
        node2user[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
