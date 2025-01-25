class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        int cnt = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string s = q.front();
                q.pop();

                if(s == endGene){
                    return cnt;
                }

                for(char ch : "ACGT"){
                    for(int i=0; i<s.size(); i++){
                        string adjString = s;
                        adjString[i] = ch;

                        if(vis.find(adjString) == vis.end() && st.find(adjString) != st.end()){
                            vis.insert(adjString);
                            q.push(adjString);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};