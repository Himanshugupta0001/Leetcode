class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;

        for(int i=0; i<n; i++){
            int curr = nums[i];
            while(!st.empty() && gcd(1LL*st.top(), 1LL*curr) != 1){
                int tp = st.top();
                st.pop();
                curr = (1LL*tp*curr/(gcd(1LL*tp, 1LL*curr)));
            }
            st.push(curr);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};