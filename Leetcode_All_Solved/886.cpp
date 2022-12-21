//NOTE: uva10158 War
class Solution {
public:
    int n;
    int set_find(const int& a, vector<int>& set){
        if(set[a] == (-1))return a;
        return set[a] = set_find(set[a], set);
    }
    inline void set_join(int a, int b, vector<int>& set){
        a = set_find(a, set);
        b = set_find(b, set);
        if(a != b)set[a] = b;
        //NOTE: for set[a] == (-1) the root, and b is a child of a
    }
    inline void set_enemy(const int& a, const int& b, vector<int>& set){
        //already check relation, not friends
        set_join(a, b+n, set);
        set_join(a+n, b, set);
    }
    inline int relation(const int& a, const int& b, vector<int>& set){
        if(set_find(a, set) == set_find(b, set))
            return 1;//friends
        return 0;
        /*else if(set_find(a, set) == set_find(b+n, set))
            return 0;//enemy
        else return 0;//unknown
        */
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        this->n = n;
         vector<int> set(2*n + 1, (-1));
         int a, b;
         for(const vector<int>& ab: dislikes){
             a = ab[0];
             b = ab[1];
             if(relation(a, b, set) == 1)return false;
             
             set_enemy(a, b, set);
         }
         return true;
    }
};
