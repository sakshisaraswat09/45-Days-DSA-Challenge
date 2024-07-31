class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==0){
                int j=i+1;
                while(nums[j]==0 && j<nums.size()-1) j++;
                if(nums[i]!=nums[j]) swap(nums[i],nums[j]);
            }
            i++;
        }
    }
};
