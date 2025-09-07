#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool issafe(vector<vector<char>>& board, int r, int c, int ch){
        for(int i=0; i<9; i++){
            //row check
            if(board[r][i] - '0' == ch)    return false;
            //column check
            if(board[i][c] - '0' == ch)    return false;
        }
        int x = (r/3)*3;
        int y = (c/3)*3;
        for(int i = x;i<x+3;i++){
            for(int j = y;j<y+3;j++){
                if(board[i][j] - '0' == ch)    return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& board,int r,int c) {
        if(r==9) return true;
        if(c==9) return f(board,r+1,0);
        if(board[r][c] != '.') return f(board,r,c+1);
        for(int j=1;j<=9;j++){
            if(issafe(board,r,c,j)){
                board[r][c] = '0' + j;
                bool result = f(board,r,c+1);
                if(result==true) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};
