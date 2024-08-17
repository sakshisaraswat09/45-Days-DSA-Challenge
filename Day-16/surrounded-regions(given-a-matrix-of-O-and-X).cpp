class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int nRow = i+dRow[k];
            int nCol = j+dCol[k];

            if(nRow>=0 && nRow<board.size() && nCol>=0 && nCol<board[0].size() && vis[nRow][nCol]==0 && board[nRow][nCol]=='O'){
                dfs(board,vis,nRow,nCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));

        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(board,vis,i,0);
            }

            if(board[i][board[0].size()-1]=='O'){
                dfs(board,vis,i,board[0].size()-1);
            }
        }

        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O'){
                dfs(board,vis,0,j);
            }

            if(board[board.size()-1][j]=='O'){
                dfs(board,vis,board.size()-1,j);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
