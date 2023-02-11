#define ceiling(a, b) ( a/b + ( (a%b==0)? 0:1 ) )
#define test 0 //1 0
#include<assert.h>
#include<limits.h>
class Solution {
public:
    vector<vector<int>> adjlist;

    bool backtrack_find_path(vector<int>& path, const int& bob, const int& root, const int& parent=(-1)){
        path.push_back(root);

        if(root == bob)return true;

        for(const int& child: adjlist[root])if(child != parent){
            if( backtrack_find_path(path, bob, child, root) == true)
                return true;//NOTE: without backtrack
        }

        //backtrack
        path.pop_back();
        return false;
    }

    void preorder(const vector<int>& amount, int& max_profit, const int& root, const int& parent=(-1), const int& profit=0){

        //NOTE: if(adjlist[root].size() == 1){
        if(adjlist[root].size() == 1 && parent != (-1)){
            max_profit = max(max_profit, profit + amount[root]);
            return;
        }

        for(const int& child: adjlist[root])if(child != parent)
            preorder(amount, max_profit, child, root, profit + amount[root]);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        vector<int> path;
        assert( backtrack_find_path(path, bob, 0) );

        int half = ceiling(path.size(), 2);
        for(int i=path.size()-1;i>=half;i--)
            amount[path[i]] = 0;
        
        if(path.size() %2 == 1)
            amount[ path[ path.size()/2 ] ] /= 2;
            //amount[path.size()/2] /= 2;//amount all even
        
        #if test == 1
        for(const int& a: amount)
            cout << a << " ";
        cout << endl;
        for(const int& p: path)
            cout << p << " ";
        cout << endl;
        #endif
        

        int max_profit = INT_MIN;
        preorder(amount, max_profit, 0);
        return max_profit;
    }
};
