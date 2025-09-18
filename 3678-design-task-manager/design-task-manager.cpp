class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp; //task->{user, priority}
    priority_queue<pair<int, int>> pq;     //{priority, task}
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0; i<n; i++){
            int user = tasks[i][0];
            int task = tasks[i][1];
            int priority = tasks[i][2];

            mp[task] = {user, priority};
            pq.push({priority, task});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            int priority = pq.top().first;
            int task = pq.top().second;
            pq.pop();

            if(mp.find(task) != mp.end() && mp[task].second == priority){
                int user = mp[task].first;
                mp.erase(task);
                return user;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */