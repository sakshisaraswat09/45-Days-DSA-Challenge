class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int max1 = nums[n],max2 = nums[n-1],max3 = nums[n-2],min1 = nums[0],min2 = nums[1];
        return max(max1*max2*max3,min1*min2*max1);
    }
};
