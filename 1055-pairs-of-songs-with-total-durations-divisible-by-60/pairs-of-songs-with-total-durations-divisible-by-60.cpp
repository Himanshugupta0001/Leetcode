class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        map<int, int> mp;
        int cnt = 0;
        mp[time[0]%60] = 1;
        for(int i=1; i<n; i++){
            int val = time[i]%60;
            int rem = (60-val)%60;

            cnt += mp[rem];
            mp[val]++;
        }
        return cnt;
    }
};