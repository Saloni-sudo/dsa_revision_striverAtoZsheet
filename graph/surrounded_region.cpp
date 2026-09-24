//question

/*
->You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board.
Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board.
 You do not need to return anything.
*/

//what it meant
/*
->okey a matrix is given which has 'x' and 'o' values in cell
->we can move adjacnet cell horizontally and vertically
->okey to make a regin we have to connect every'o' values cell.
->okey a region with values as '0' is surrounded when none of them exist on the border
->to capture it reaplce it with
->question asked about to does not return anything
*/

//thought process
/*
->first,take m and n as input from the user
->after that,take user input values in the cell
->then you have to do nothing just traverse on the border where 'o' as value in the cell
->mark them '#' and do bfs or dfs call on them to visit those cells which are '0' and connected with the border
->after marking each connected cell with -1 
->again traverse the array which evry is '0' mark them as 'x' and whichever are '#' unmark them as'o'.
->to check the correct output we trvarese the matrix
*/

//code
#include<iostream>
#include<vector>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&matrix,int &m,int &n){
      vector<int>delrow={0,0,-1,1};
      vector<int>delcol={-1,1,0,0};

      for(int k=0;k<4;k++){
        int newrow=i+delrow[k];
        int newcol=j+delcol[k];

        if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && matrix[newrow][newcol]=='O'){
            matrix[newrow][newcol]='#';
            dfs(newrow,newcol,matrix,m,n);
        }

      }
}

using namespace std;
 void update(int &m,int &n,vector<vector<char>>&matrix){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                if(matrix[i][j]=='O'){
                    matrix[i][j]='#';
                    dfs(i,j,matrix,m,n);
                }
            }
        }
    }
 }



int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>>matrix(m,vector<char>(n,0));


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    update(m,n,matrix);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='O') matrix[i][j]='X';
            else if(matrix[i][j]=='#') matrix[i][j]='O';
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }

    return 0;
}