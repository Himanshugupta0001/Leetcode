class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> ss;
        string res;

        int k = 0;

        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                k = k*10 + s[i] - '0';
            }
            else if(s[i] == '['){
                st.push(k);
                k = 0;
                ss.push(res);
                res = "";
            }
            else if(s[i] == ']'){
                int j = st.top();
                st.pop();
                string temp = res;
                res = ss.top();
                ss.pop();

                while(j > 0){
                    res += temp;
                    j--;
                }
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};