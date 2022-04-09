/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> dfs_order;
    int cur_dfs_idx = 0;
    void dfs(const NestedInteger& ni){
        if(ni.isInteger() == true){
            dfs_order.push_back(ni.getInteger());//leaf
            return;
        }
        
        for(const NestedInteger& child:ni.getList())
            dfs(child);
    }
public:
    //NOTE: only the leaf holds ints.
    //NOTE: isInteger():isLeaf() getInteger():->val getList():get its children
    //NOTE: ans is dfs order
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0;i<nestedList.size();i++)
            dfs(nestedList[i]);
    }
    
    int next() {
        return this->dfs_order.at( (this->cur_dfs_idx)++ );
    }
    
    bool hasNext() {
        return this->cur_dfs_idx < this->dfs_order.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
