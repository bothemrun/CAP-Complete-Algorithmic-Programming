class Solution {
public:
    unordered_map<int, vector<int>> pid2children;
    vector<int> killed;
    void preorder(int root_pid){
        killed.push_back(root_pid);
        for(int child_pid: pid2children[root_pid])
            preorder(child_pid);
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        for(int i=0;i<n;i++){
            if(pid2children.count(ppid[i]) == 0)
                pid2children[ ppid[i] ] = vector<int>({pid[i]});
            else pid2children[ ppid[i] ].push_back(pid[i]);
        }
        
        
        preorder(kill);
        return killed;
    }
};
