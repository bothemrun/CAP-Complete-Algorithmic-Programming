/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//O(m*n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};
    
    const int not_visited = (-2);
    void dfs(vector<vector<int>>& ans, int i, int j){
        if(!(0<=i && i<m && 0<=j && j<n)) return;

        if(ans[i][j] != not_visited) return;
        ans[i][j] = (-1);

        for(int k=0;k<(int)di.size();k++){
            dfs(ans, i+di[k], j+dj[k]);
        }
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        this->m = m;
        this->n = n;
        vector<vector<int>> ans(m, vector<int>(n, not_visited));

        int i=0, j=0, dir=0;
        ListNode* cur = head;
        int cnt = 0;
        while(cur != nullptr){
            ans[i][j] = cur->val;
            cur = cur->next;

            int tmpi = i+di[dir];
            int tmpj = j+dj[dir];
            if( !(0<=tmpi && tmpi<m && 0<=tmpj && tmpj<n) || ans[tmpi][tmpj] != not_visited ){
                dir = (dir+1)%4;
            }

            i += di[dir];
            j += dj[dir];
            //edge case
            if(++cnt == m*n) break;
            assert(0<=i && i<m);
            assert(0<=j && j<n);
        }

        //edge case
        if(cnt != m*n && ans[i][j] == not_visited){
            dfs(ans, i, j);
        }
        return ans;
    }
};
