class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto i=mp.begin(); i != mp.end(); i++){
            minHeap.push({i->second, i->first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            int x = minHeap.top().second;
            ans.push_back(x);
            minHeap.pop();
        }
        return ans;
    }
};