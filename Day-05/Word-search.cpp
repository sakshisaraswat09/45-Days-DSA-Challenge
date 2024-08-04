class Solution {
public:
    bool solve(int sr,int sc,vector<vector<char>>& board,string &word,int k,vector<vector<int>>& vis){
        if(k>=word.length()) return true;
        int i=sr,j=sc;
        bool a=0,b=0,c=0,d=0;
        if(i+1<board.size() && board[i+1][j]==word[k] && !vis[i+1][j]){
            vis[i+1][j]=1;
            a = solve(i+1,j,board,word,k+1,vis);
            vis[i+1][j]=0;
        }
        if(j+1<board[0].size() && board[i][j+1]==word[k] && !vis[i][j+1]){
            vis[i][j+1]=1;
            b = solve(i,j+1,board,word,k+1,vis);
            vis[i][j+1]=0;
        }
        if(i-1>=0 && board[i-1][j]==word[k] && !vis[i-1][j]){
            vis[i-1][j]=1;
            c = solve(i-1,j,board,word,k+1,vis);
            vis[i-1][j]=0;
        }
        if(j-1>=0 && board[i][j-1]==word[k] && !vis[i][j-1]){
            vis[i][j-1]=1;
            d = solve(i,j-1,board,word,k+1,vis);
            vis[i][j-1]=0;
        }
        return a || b|| c || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    bool temp = solve(i,j,board,word,1,vis);
                    vis[i][j]=0;
                    if(temp) return true;
                }
            }
        }
        return false;
    }
};
