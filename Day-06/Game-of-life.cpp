class Solution {
public:
    void solve(vector<vector<int>>& board,int &temp,int i,int j){
        int dRow[]={-1,0,1,0};
        int dCol[]={0,-1,0,1};
        int cnt = 0;
        for(int k=0;k<4;k++){
            int nRow = i+dRow[k];
            int nCol = j+dCol[k];
            if(nRow>=0 && nRow<board.size() && nCol>=0 && nCol<board[0].size() && board[nRow][nCol]==1) cnt++;
        }
        int tRow[]={-1,-1,1,1};
        int tCol[]={-1,1,-1,1};
        for(int k=0;k<4;k++){
            int nRow = i+tRow[k];
            int nCol = j+tCol[k];
            if(nRow>=0 && nRow<board.size() && nCol>=0 && nCol<board[0].size() && board[nRow][nCol]==1) cnt++;
        }
        if(temp==1){
            if(cnt<2){
                temp=0;
            }else if(cnt==2 || temp==3){
                temp=1;
            }else if(cnt>3){
                temp=0;
            }
        }else if(temp==0 && cnt==3){
            temp=1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>v=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = board[i][j];
                solve(v,temp,i,j);
                board[i][j]=temp;
            }
        }
        
    }
};
