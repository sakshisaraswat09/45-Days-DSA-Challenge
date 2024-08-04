class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int total = m*n;
        int count = 0;
        int s1=0,s2=0,e1=n-1,e2=m-1;
        while(count<total){
            for(int i=s1;i<=e2 && count<total;i++){
                ans.push_back(matrix[s1][i]);
                count++;
            }
            for(int i=s2+1;i<=e1 && count<total;i++){
                ans.push_back(matrix[i][e2]);
                count++;
            }
            for(int i=e2-1;i>=s1 && count<total;i--){
                ans.push_back(matrix[e1][i]);
                count++;
            }
            for(int i=e1-1;i>s2 && count<total;i--){
                ans.push_back(matrix[i][s2]);
                count++;
            }
            s1++;
            s2++;
            e1--;
            e2--;
        }
        return ans;
    }
};
