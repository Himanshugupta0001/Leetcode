class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string token = "";
        vector<string> s1;

        while(getline(ss, token, ' ')){
            if(!token.empty()){
                s1.push_back(token);
            }
        }

        int n = s1.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            swap(s1[l], s1[r]);
            l++;
            r--;
        }
        
        string ans = "";
        for(int i=0; i<s1.size(); i++){
            ans += s1[i];
            ans += i < s1.size()-1 ? " " : "";
        }
        return ans;
    }
};