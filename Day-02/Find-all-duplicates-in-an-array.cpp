class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            if(v[i]==2) ans.push_back(i);
        }
        return ans;
    }
};
