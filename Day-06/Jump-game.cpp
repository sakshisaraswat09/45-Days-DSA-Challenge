class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        vector<int>vis(nums.size(),0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int i=q.front();
            q.pop();
            int n = nums[i];
            int cnt=0;
            while(cnt<n){
                cnt++;
                int t = i+cnt;
                if(!vis[t]){
                    vis[t]=1;
                    q.push(t);
                }
                if(t==nums.size()-1) return true;
            }
        }
        return false;
    }
};
