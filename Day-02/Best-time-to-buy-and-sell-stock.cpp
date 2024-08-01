class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = prices.back();
        vector<int>v(prices.size(),0);
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]>maxi){
                maxi=prices[i];
            }else{
                v[i]=maxi;
            }
        }
        int ans = 0;
        for(int i=0;i<v.size();i++){
            int diff = v[i]-prices[i];
            ans = max(ans,diff);
        }
        if(prices.size()==1 || ans==0) return 0;
        return ans;
    }
};
