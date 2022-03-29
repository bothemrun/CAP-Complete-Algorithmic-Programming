class Solution {
private:
    vector<vector<int>> children;
    vector<long long> size_subtree;
    
    long long max_product = 0;
    int nodes_with_max_product = 0;
    
    void get_child(const vector<int>& parents, int root){
        children.resize(parents.size());
        for(int i=0;i<parents.size();i++)if(i != root)children[parents[i]].push_back(i);
    }
    
    int get_size_subtree(int root){
        long long size = 0;
        for(int c:children[root])size += get_size_subtree(c);
        
        size += 1;//self
        size_subtree[root] = size;
        return size;
    }
    void subtree_size_product(int root, const int& highest_root){
        for(int c:children[root]) subtree_size_product(c, highest_root);
        
        long long product = 1;//int product = 1;
        for(int c:children[root]) product *= size_subtree[c];
        
        if(root != highest_root) product *= (size_subtree[highest_root] - size_subtree[root]);
        
        if(product == max_product){
            nodes_with_max_product++;
        }else if(product > max_product){
            max_product = product;
            nodes_with_max_product = 1;
        }
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        //build tree's children
        get_child(parents, 0);
        //get size of subtree
        size_subtree.resize(children.size());
        get_size_subtree(0);
        //traverse
        subtree_size_product(0, 0);
        return nodes_with_max_product;
    }
};
