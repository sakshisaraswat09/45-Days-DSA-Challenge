class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;
        int sum=0,ans=INT_MIN;
        while(i<k){
            sum+=cardPoints[i];
            i++;
        }
        i--;
        int n = cardPoints.size();
        ans=max(ans,sum);
        for(int j=n-1;j>n-k-1;j--){
            sum-=cardPoints[i--];
            sum+=cardPoints[j];
            ans=max(ans,sum);
        }
        return ans;
    }
};
