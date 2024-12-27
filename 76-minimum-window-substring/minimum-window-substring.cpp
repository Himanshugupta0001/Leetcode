class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int minLen = 1e9;
        int sIndex = -1;
        vector<int> hash(256, 0);

        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }

        while(r < n){
            if(hash[s[r]] > 0){
                cnt = cnt+1;
            }
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt = cnt - 1;
                }
                l++;
            }
            r++;
        }

        if(sIndex == -1){
            return "";
        }
        else{
            return s.substr(sIndex, minLen);
        }
    }
};