class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //find nodes with indegree == 0
        vector<int> indegree (n, 0);
        for(const vector<int>& e:edges) indegree.at(e[1])++;
        
        vector<int> ans;
        for(int i=0;i<n;i++)if(indegree[i] == 0)ans.push_back(i);
        return ans;
    }
};
