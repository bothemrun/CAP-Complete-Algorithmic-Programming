#include<unordered_map>
#include<unordered_set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Task{
public:
    int userId;
    string desc;
    int due;

    unordered_set<string> tagset;

    Task(const int& userId, const string& taskDescription, const int& dueDate, const vector<string>& tags){
        this->userId = userId;
        desc = taskDescription;
        due = dueDate;

        for(const string& tag: tags)
            tagset.insert(tag);
    }
};

class TodoList {
public:
    int cur_taskId = 1;
    unordered_map<int, class Task*> taskId2task;

    unordered_map<int, unordered_set<int> > userId2taskId;

    //NOTE: capture variables in the enclosing scope.
    /*auto cmp_fn = [&](const int& id1, const int& id2){
        return taskId2task.at(id1)->due < taskId2task.at(id2)->due;
    };*/

    TodoList() {

    }
    
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        int taskId = cur_taskId++;
        taskId2task[ taskId ] = new Task(userId, taskDescription, dueDate, tags);
        
        userId2taskId[ userId ].insert(taskId);
        return taskId;
    }

    /*static bool cmp_fn(const int& id1, const int& id2){
        return taskId2task.at(id1).due < taskId2task.at(id2).due;
    }*/
    
    vector<string> getAllTasks(int userId) {
        if(
            userId2taskId.count(userId) == 0 ||
            userId2taskId[userId].size() == 0
        ) return vector<string>();

        vector<int> taskIds;
        for(const int& id: userId2taskId[userId] )
            taskIds.push_back(id);
        

        //NOTE: capture variables in the enclosing scope.
        auto cmp_fn = [&](const int& id1, const int& id2){
            return taskId2task.at(id1)->due < taskId2task.at(id2)->due;
        };
        sort(taskIds.begin(), taskIds.end(), cmp_fn);
        
        vector<string> desc;
        for(const int& id: taskIds)
            desc.push_back( taskId2task.at(id)->desc );
        return desc;
    }
    
    vector<string> getTasksForTag(int userId, string tag) {
        if(
            userId2taskId.count(userId) == 0 ||
            userId2taskId[userId].size() == 0
        ) return vector<string>();

        vector<int> taskIds;
        for(const int& id: userId2taskId[userId])if( taskId2task.at(id)->tagset.count(tag) != 0)
            taskIds.push_back(id);
        

        //NOTE: capture variables in the enclosing scope.
        auto cmp_fn = [&](const int& id1, const int& id2){
            return taskId2task.at(id1)->due < taskId2task.at(id2)->due;
        };
        sort(taskIds.begin(), taskIds.end(), cmp_fn);
        vector<string> desc;
        for(const int& id: taskIds)
            desc.push_back( taskId2task.at(id)->desc );
        return desc;
    }
    
    void completeTask(int userId, int taskId) {
        if(taskId >= cur_taskId) return;
        if( taskId2task.count(taskId) == 0 ) return;
        if( taskId2task.at(taskId)->userId != userId ) return;

        delete taskId2task.at(taskId);
        taskId2task.erase(taskId);
        userId2taskId.at(userId).erase(taskId);
    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
