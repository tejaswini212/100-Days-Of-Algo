#include<bits/stdc++.h>
using namespace std;

int move_x[8]={2,1,-1,-2,-2,-1,1,2};
int move_y[8]={1,2,2,1,-1,-2,-2,-1};

bool validateMove(vector<vector<int>> &board,int row,int col){
    if(row<8 && row>=0 && col<8 && col>=0 && board[row][col]==0) 
	return true;
    else
        return false;
}

bool solve(vector<vector<int>> &board,int row,int col,int counter){
    if(counter>=65)
            return true;
    for(int i=0;i<8;i++){
        int new_x = row+move_x[i];
        int new_y = col+move_y[i];
        if(validateMove(board,new_x,new_y))
        {
            board[new_x][new_y]=counter;
            if(solve(board,new_x,new_y,counter+1))//==true)
                return true;
            else
                board[new_x][new_y]=0;
        }
    }
    return false;
}

int main(){
    int m=8,n=8;
    vector<vector<int>> board(n,vector<int>(m,0));
    
    board[0][0]=1;
    solve(board,0,0,2);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
