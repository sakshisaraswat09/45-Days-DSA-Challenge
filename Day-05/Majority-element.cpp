class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=-1,cnt=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            int x = nums[i];
            int j=i;
            while(j<n && nums[i]==nums[j]){
                j++;
                cnt++;
            }
            if(cnt>n/2){
                ans=nums[i];
                return ans;
            }else{
                cnt=0;
                i++;
            }
        }
        return ans;
    }
};
