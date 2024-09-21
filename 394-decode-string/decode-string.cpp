class Solution {
public:
    string decode(const string& s, int& ptr){
        int n = s.length();

        string ans = "";

        while(n > ptr && s[ptr] != ']'){
            if(isdigit(s[ptr])){
                int k = 0;
                while(isdigit(s[ptr]) && ptr < n){
                    k = k*10 + s[ptr] - '0';
                    ptr++;
                }
                ptr++;
                string res = decode(s, ptr);
                ptr++;
                while(k > 0){
                    ans += res;
                    k--;
                }
            }
            else{
                ans += s[ptr];
                ptr++;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int ptr = 0;
        return decode(s, ptr);
    }
};