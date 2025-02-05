class Solution {
public:
    vector<int> findnse(vector<int>&nums){
        int n=nums.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpsee(vector<int>&nums){
        int n=nums.size();
        vector<int>psee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            psee[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return psee;
    }
    long long subarrmins(vector<int>&nums){
        vector<int>nse=findnse(nums);
        vector<int>psee=findpsee(nums);
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            sum=sum+ (right*left*1LL*nums[i]);
        }
        return sum;
    }
    vector<int> findnge(vector<int>&nums){
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            nge[i]=st.empty() ? n: st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findpge(vector<int>&nums){
        int n=nums.size();
        vector<int>pge(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]<=nums[i]){
                st.pop();
            }
            pge[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return pge;
    }
    long long  subarrmax(vector<int>&nums){
        vector<int>nge=findnge(nums);
        vector<int>pge=findpge(nums);

        long long sum=0;

        for(int i=0;i<nums.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            sum=sum+ (left*right*1LL*nums[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long maxsum=subarrmax(nums);
        long long minsum=subarrmins(nums);

        return maxsum-minsum;
    }
};