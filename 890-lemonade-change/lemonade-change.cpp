class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for(auto it : bills){
            int change = it - 5;
            if(change == 5){
                if(mp[5] == 0){
                    return false;
                }
                else{
                    mp[5]--;
                }
            }
            else if(change == 15){
                if(mp[5] >= 1 && mp[10] >= 1){
                    mp[5]--;
                    mp[10]--;
                }
                else if(mp[5] >= 3){
                    mp[5] += -3;
                }
                else{
                    return false;
                }
            }
            mp[it]++;
        }
        return true;
    }
};