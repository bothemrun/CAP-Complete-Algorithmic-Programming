class Solution {
private:
    inline int get_level(int label){
        int level = 1;
        int rightmost_label = 1;
        while(rightmost_label < label){
            level++;
            rightmost_label = rightmost_label*2 + 1;
        }
        return level;
    }
    inline int reverse_label(int label, int level){
        //only reverse even level, whether real or not
        if(level %2 == 1)return label;
        
        int leftmost_label_this_level = (1 << (level-1) );
        int leftmost_label_next_level = (1 << (level-1 + 1) );
        int rightmost_label_this_level = leftmost_label_next_level - 1;
        return rightmost_label_this_level - label + leftmost_label_this_level;
    }
public:
    vector<int> pathInZigZagTree(int label) {
        //NOTE: complete property : top root=1, left=root*2, right=root*2+1
        int level = get_level(label);
        
        vector<int> ans_stack;
        int real_label = reverse_label(label, level);
        while( real_label > 0 ){
            ans_stack.push_back( reverse_label(real_label, level) );
            
            real_label /= 2;
            level--;
        }
        
        vector<int> ans;
        for(int i=ans_stack.size()-1;i>=0;i--)ans.push_back(ans_stack[i]);
        return ans;
    }
};
