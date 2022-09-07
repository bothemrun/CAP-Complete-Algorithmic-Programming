/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include<unordered_map>
#include<assert.h>
class Solution {
public:
    unordered_map<int,int> id2idx;
    int import_sum = 0;
    void postorder(const vector<Employee*>& employees, int root_id){
        unordered_map<int,int>::iterator f = id2idx.find(root_id);
        if(f == id2idx.end())assert(0);
        int root_idx = f->second;
        
        for(const int sub_id:employees.at(root_idx)->subordinates)
            postorder(employees, sub_id);
        
        import_sum += employees.at(root_idx)->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0;i<employees.size();i++)
            id2idx[employees[i]->id] = i;
        
        postorder(employees, id);
        return import_sum;
    }
};
