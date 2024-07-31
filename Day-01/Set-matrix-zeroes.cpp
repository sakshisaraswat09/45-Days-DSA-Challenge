class Solution {
public:
    void solve(vector<vector<int>>& matrix,int sr,int sc){
        for(int i=0;i<matrix.size();i++){
            matrix[i][sc]=0;
        }
        for(int j=0;j<matrix[0].size();j++){
            matrix[sr][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>vis(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) vis[i][j]=1;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0 && vis[i][j]==1) solve(matrix,i,j);
            }
        }
    }
};
