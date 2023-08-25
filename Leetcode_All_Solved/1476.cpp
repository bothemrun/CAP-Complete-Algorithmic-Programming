//m0
//array of all the updates.
//for query, go thru the update array from the new to the old.
//if the query range not within all the update array, then use the original rectangle.

//complexity:
//update in O(1). query in O(update call)
// x := update calls, y := query calls.
//then complexity = O(x*1 + y*x) = O(xy)

//by the arithmetic inequality (x+y)/2 >= sqrt(xy)
//so complexity <= ( (x+y)/2 )^2 = (500 calls / 2)^2 = O(6e4)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class SubrectangleQueries {
public:
    vector<vector<int>> updates;

    vector<vector<int>>* rec_ptr;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        //optim: assume the rectangle doesn't get destroyed before all calls.
        
        rec_ptr = &rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        updates.push_back( vector<int>({ row1, col1, row2, col2, newValue }) );
    }
    
    int getValue(int row, int col) {
        int int_size = updates.size();
        for(int i=int_size-1;i>=0;i--)if(
            updates[i][0] <= row &&
            row <= updates[i][2] &&
            updates[i][1] <= col &&
            col <= updates[i][3]
        ){
            return updates[i][4];
        }

        return rec_ptr->at(row).at(col);
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
