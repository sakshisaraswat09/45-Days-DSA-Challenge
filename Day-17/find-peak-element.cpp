class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            if(i+1<nums.size() && nums[i]>nums[i+1]) cnt++;
            if(i>0 && nums[i]>nums[i-1]) cnt++;

            if(i!=0 && i!=nums.size()-1 && cnt==2) return i;
            else if((i==0 || i==nums.size()-1) && cnt==1) return i;
        }
        return 0;
    }
    
};


// 2nd approach

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        else if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;

        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) return i;
        }
        return 0;
    }    
};
