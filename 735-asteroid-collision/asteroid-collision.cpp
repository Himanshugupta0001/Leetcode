class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top() < abs(asteroids[i]) && st.top() > 0){
                    st.pop();
                }
                if(!st.empty() && abs(asteroids[i]) == st.top()){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result), end(result));
        return result;
    }
};