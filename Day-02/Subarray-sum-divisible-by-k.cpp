class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>sum(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i]=nums[i]+sum[i-1];
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int rem = sum[i]%k;
            while(rem<0){
                rem+=k;
            }
            if(mp[rem]){
                ans+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]=1;
            }
        }
        return ans;
    }
};
