class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=temp.back()){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return temp.size();
    }
};
