class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //1-based
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        for(const vector<int>& e: trust){
            indegree[e[1]]++;
            outdegree[e[0]]++;
        }

        for(int i=1;i<=n;i++)if(indegree[i] == n-1 && outdegree[i] == 0)
            return i;
        return (-1);
    }
};
