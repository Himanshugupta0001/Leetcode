class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> hash(26);
        for(char ch : brokenLetters){
            hash[ch - 'a'] = true;
        }

        int cnt = 0;
        bool flag = true;
        for(char &ch : text){
            if(ch == ' '){
                if(flag){
                    cnt++;
                }
                flag = true;
            }
            else if(hash[ch - 'a'] == true){
                flag = false;
            }
        }

        if(flag){
            cnt++;
        }
        
        return cnt;
    }
};