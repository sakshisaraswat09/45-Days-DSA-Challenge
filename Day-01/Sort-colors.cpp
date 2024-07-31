class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0,ones =0,twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroes++;
            else if(nums[i]==1) ones++;
            else twos++;
        }
        int i=0,k=0;
        while(i<zeroes){
            nums[k++]=0;
            i++;
        }
        i=0;
        while(i<ones){
            nums[k++]=1;
            i++;
        }
        i=0;
        while(i<twos){
            nums[k++]=2;
            i++;
        }
        
    }
};
