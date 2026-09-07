class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')dfs(board,ans,0,i);
            if(board[n-1][i]=='O')dfs(board,ans,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')dfs(board,ans,i,0);
            if(board[i][m-1]=='O')dfs(board,ans,i,m-1);
        }
        board=ans;
    }
private:
    void dfs(vector<vector<char>>& board,vector<vector<char>>& ans,int i,int j){
        int n=board.size();
        int m=board[0].size();
        ans[i][j]='O';
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && ans[nx][ny]=='X' ){
                dfs(board,ans,nx,ny);
            }
        }
    }
};
