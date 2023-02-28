class Vector2D {
public:
    vector<vector<int>>::iterator it1;
    vector<vector<int>>::iterator it1_end;
    vector<int>::iterator it2;
    inline void nonempty(){
        if(hasNext() == false)return;

        while(it2 == it1->end()){
            it1++;
            if(hasNext() == false)return;
            it2 = it1->begin();
        }
    }
    Vector2D(vector<vector<int>>& vec) {
        it1 = vec.begin();
        it1_end = vec.end();

        if(hasNext() == false)return;
        it2 = it1->begin();

        nonempty();
    }
    
    int next() {
        int val = *it2;
        it2++;

        nonempty();
        return val;
    }
    
    bool hasNext() {
        return it1 != it1_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
