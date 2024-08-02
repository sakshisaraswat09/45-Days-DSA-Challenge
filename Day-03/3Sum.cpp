class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-2){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==-(nums[i])){
                    while(j<nums.size()-1 && nums[j]==nums[j+1]) j++;
                    while(k>0 && nums[k]==nums[k-1]) k--;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[j]+nums[k]>-(nums[i])) k--;
                else j++;
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};
