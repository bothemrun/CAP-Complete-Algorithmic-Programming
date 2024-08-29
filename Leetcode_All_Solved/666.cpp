class Solution {
public:
    unordered_map<int,int> node2val;
    int ans = 0;
    int posto(int node){
        int cnt = 0;//count of path forks
        for(int child: {node*2, node*2+1})if(node2val.find(child) != node2val.end()){
            cnt += posto(child);
        }

        //leaf
        if(cnt == 0){
            ans += node2val[node];
            return 1;
        }else{
            ans += cnt * node2val[node];
            return cnt;
        }
    }

    int pathSum(vector<int>& nums) {
        for(const int& x: nums){
            int node = ( (int)pow(2, x/100 - 1 ) - 1 ) + (x%100/10);
            node2val[node] = x%10;
        }

        const int root = 1;
        posto(root);
        return ans;
    }
};
