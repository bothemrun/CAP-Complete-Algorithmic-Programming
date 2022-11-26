class Solution {
private:
    int set_find(vector<int>& set, const int& a){
        if(set[a] == (-1))return a;
        return (set[a] = set_find(set, set[a]));
    }
    void set_join(vector<int>& set, int a, int b){
        a = set_find(set, a);
        b = set_find(set, b);
        if(a != b) set[a] = b;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> set(26, (-1));
        for(string& equation: equations)if(equation[1] == '=')
            set_join(set, (int)(equation[0] - 'a'), (int)(equation[3] - 'a') );
        
        for(string& equation: equations)if(equation[1] == '!'){
            if(set_find(set, (int)(equation[0] - 'a') ) == set_find(set, (int)(equation[3] - 'a') )   )
                return false;
        }
        return true;
    }
};
