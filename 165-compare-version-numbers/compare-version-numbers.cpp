class Solution {
public:
    vector<string> getTokens(string version){
        stringstream ss(version);

        string token = "";
        vector<string> tokens;

        while(getline(ss, token, '.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> s1 = getTokens(version1);
        vector<string> s2 = getTokens(version2);

        int n = s1.size();
        int m = s2.size();
        int i = 0;

        while(i < n || i < m){

            int a = i < n ? stoi(s1[i]) : 0;
            int b = i < m ? stoi(s2[i]) : 0;


            if(a < b){
                return -1;
            }
            else if(a > b){
                return 1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};