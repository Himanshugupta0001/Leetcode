class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int maxLen = 0;
        int i = 0;

        for(int j=0; j<n; j++){
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};