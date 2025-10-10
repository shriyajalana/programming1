#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& board,int r,int c,int val){
    for(int i=0;i<9;i++){
        if(board[r][i]==val || board[i][c]==val) return false;
        if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            if(board[r][c]==0){
                for(int val=1;val<=9;val++){
                    if(isValid(board,r,c,val)){
                        board[r][c]=val;
                        if(solve(board)) return true;
                        board[r][c]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> board={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solve(board);
    for(auto &row:board){for(int x:row) cout<<x<<" "; cout<<"\n";}
}
