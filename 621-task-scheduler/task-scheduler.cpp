class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26, 0);
        for(char &ch : tasks){
            hash[ch-'A']++;
        }

        priority_queue<int> maxHeap;
        for(int i=0; i<26; i++){
            if(hash[i] > 0){
                maxHeap.push(hash[i]);
            }
        }

        int cnt = 0;
        while(!maxHeap.empty()){
            vector<int> temp;
            for(int i=1; i<=(n+1); i++){
                if(!maxHeap.empty()){
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f : temp){
                if(f > 0){
                    maxHeap.push(f);
                }
            }
            
            if(maxHeap.empty()){
                cnt += temp.size();
            }
            else{
                cnt += n+1;
            }
        }
        return cnt;
    }
};